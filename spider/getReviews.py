import re
import http.client

import json


def getPage(movieID, startID):
    conn = http.client.HTTPConnection("movie.douban.com")
    try:
        conn.request("GET","/subject/%d/reviews?start=%d&filter=&score=1&limit=20"%(movieID, startID))
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
    reviews = []
    page0 = getPage(movieID, 0)
    numberOfReviews = (re.search('<span class="total">\(共 (\d+) 条\)</span>', page0))
    numberOfReviews = numberOfReviews.group(1) if numberOfReviews else 0
    numberOfReviews = int(numberOfReviews)
    reviews += parsePage(page0)
    for startID in range(27, numberOfReviews+1, 27):
        print("Loading %d: %d of %d" % (movieID, startID, numberOfReviews))
        reviews += parsePage(getPage(movieID, startID))
    return reviews
    
    
def doMovie(movieID):
    f = open("output/%d.json" % movieID, "w")
    f.write(json.dumps(getReviews(movieID), indent=1))
    f.close()

def main():
    f = open("movielist.json")
    movieList = json.loads(filter(f.read()))
    for movie in movieList:
        print(movie)
        doMovie(int(movie['id']))

main()