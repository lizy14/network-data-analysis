import re
import http.client
import json
import threading
import os
import time

def getPage(movieID, startID):
    conn = http.client.HTTPConnection("movie.douban.com")
    # conn = http.client.HTTPConnection("localhost", 1080)
    # conn.set_tunnel("movie.douban.com")
    try:
        conn.request("GET","/subject/%d/reviews?start=%d&filter=&limit=20"%(movieID, startID),headers={ 
            "Accept": "text/html, application/xhtml+xml, image/jxr, */*",

            "Accept-Language": "zh-Hans-CN, zh-Hans; q=0.8, en-US; q=0.5, en; q=0.3",
            "Connection": "Keep-Alive",
            "Cookie": "bid=Dz6aeVd3SFk; _pk_id.100001.4cf6=0b5f6e59908ef738.1444804967.1.1444804967.1444804967.; _pk_ses.100001.4cf6=*",
            "Host": "movie.douban.com",
            "User-Agent": "Mozilla/5.0 (Windows NT 10.0) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/42.0.2311.135 Safari/537.36 Edge/12.10240"
        })
    except:
        print('Connection Failed')
        conn.close()
        return ''
        
    resp = conn.getresponse()
    
    if resp.status==200:
        page = str(resp.read(), 'UTF-8', 'ignore')
        conn.close()
        return page
    else:
        print('Error %d %d: HTTP CODE %d: %s' % (movieID, startID, resp.status, resp.reason))
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
        if(not startID):
            break;
        startID = int(startID.group(1))
        print("Loading %d: %d of %d" % (movieID, startID, numberOfReviews))
        page = getPage(movieID, startID)
        reviews += parsePage(page)
        time.sleep(10)

    print("Finishing %d" % movieID)
    return reviews
    
    
def doMovie(movieID):
    filename = "output/%d.json" % movieID
    if(os.path.isfile(filename)):
        print("Jumping %d" % movieID)
        return
    result = getReviews(movieID)
    if(not result):
        print("Empty %d" % movieID)
        return
    result = json.dumps(result, indent=1)
    f = open(filename, "w")
    f.write(result)
    f.close()

def doSubList(subList):
    for movie in subList:
        doMovie(int(movie['id']))
def main():
    f = open("movielist.json")
    movieList = json.loads(filter(f.read()))
    f.close()
    
    # cut movieList into several parts for multi-threading
    numberOfMovies = len(movieList)
    n = 1 # number of threads
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