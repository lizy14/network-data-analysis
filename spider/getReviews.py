﻿import re
import http.client
import json
import threading

def getPage(movieID, startID):
    conn = http.client.HTTPConnection("movie.douban.com")
    try:
        conn.request("GET","/subject/%d/reviews?start=%d&filter=&limit=20"%(movieID, startID))
    except:
        print('Connection Failed')
        conn.close()
        return ''
        
    resp = conn.getresponse()
    
    if resp.status==200:
        page = str(resp.read(), 'UTF-8')
        conn.close()
        return page
    else:
        print('HTTP CODE %d: %s' % (resp.status, resp.reason))
        conn.close()
        return ''

def filter(text):
    #handle UnicodeEncodeError
    return  text.encode('GBK', 'ignore').decode('GBK')        
    
def parsePage(html):
        html = filter(html)
        results=[]
        match = re.findall('<a href="http://movie.douban.com/people/([^/]+?)/" class="">([^<]+?)</a>[^<]+?<span class="allstar(\d+)" title="[^/]+"></span>',html)
        for item in match:
            results.append({"user": item[0], "score": item[2]})
        return results

def getReviews(movieID):
    print("Starting %d" % movieID)
    reviews = []
    
    page = getPage(movieID, 0)
    
    numberOfReviews = (re.search('<span class="total">\(共 (\d+) 条\)</span>', page))
    numberOfReviews = numberOfReviews.group(1) if numberOfReviews else 0
    numberOfReviews = int(numberOfReviews)
    
    reviews += parsePage(page)
    
    while 1:
        startID = re.search('<a href="\?start=(\d+)&amp;filter=&amp;limit=20" data-page="" class="next">后一页</a>',page)
        print(startID)
        if(not startID):
            break;
        startID = int(startID.group(1))
        print("Loading %d: %d of %d" % (movieID, startID, numberOfReviews))
        page = getPage(movieID, startID)
        reviews += parsePage(page)
    return reviews
    
    
def doMovie(movieID):
    f = open("output/%d.json" % movieID, "w")
    f.write(json.dumps(getReviews(movieID), indent=1))
    f.close()

def doSubList(subList):
    for movie in subList:
        doMovie(int(movie['id']))
def main():
    f = open("movielist.json")
    movieList = json.loads(filter(f.read()))
    f.close()
    # movieList = movieList[100:108]
    
    # cut movieList into several parts for multi-threading
    numberOfMovies = len(movieList)
    n = 4 # number of threads
    j = numberOfMovies//n  
    k = numberOfMovies%n 
    subLists = []
    for i in range(0,(n-1)*j,j):
        subLists.append(movieList[i:i+j])  
    subLists.append(movieList[(n-1)*j:])
    
    threads = []
    for subList in subLists:
        threads.append(threading.Thread(target=doSubList,args=[subList]))
    for t in threads:
        t.setDaemon(True)
        t.start()
    
    for t in threads:
        t.join()

main()