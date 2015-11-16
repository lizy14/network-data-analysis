import json
import os

totals = {}

# userID as key, a list of {movies, score} as value
def makeUserList():
    movieList = json.load(open("data/movielist.json"))
    
    # movieList = movieList
    
    users = {} 
    for movie in movieList:
        movieID = movie['id'];
        print("Processing %s" % movieID)
        filename = "data/%s.json" % movieID
        if(os.path.isfile(filename)):
            reviews = json.load(open(filename))
            totals[movieID] = dict()
            totals[movieID]['numberOfReviews'] = len(reviews)
            for review in reviews:
                if(review['user'] not in users):
                    users[review['user']]=[]
                newItem = {
                    'movieID': movieID, 
                    'score': review['score']
                }
                if(newItem not in users[review['user']]):
                    users[review['user']].append(newItem)
        else:
            print("File not found: %s" % filename)
    return users
    
    
def getKeyName(idA, idB):
    
    list = [idA, idB]
    list.sort()
    return "%s,%s:%s,%s" % (list[0],list[1],totals[list[0]],totals[list[1]])
    
# edges
def makeGraph(userList):
    movieList = json.load(open("data/movielist.json"))

    for movie in movieList:
        movieID = movie['id'];
        filename = "data/%s.json" % movieID
        if(os.path.isfile(filename)):
            reviews = json.load(open(filename))
            totals[movieID] = len(reviews)
    
    print("Counting %s movies" % len(totals))
            
    graph = {}
    nUsers = {}
    print("Counting %d users" % len(userList))
    for userID in userList:
        userReviews = userList[userID]
        
        n = len(userReviews)
        if n not in nUsers:
            nUsers[n]=0
        nUsers[n] += 1;
        
        for i in range(0, n-1):
            for j in range(0, i-1):
                key = getKeyName(userReviews[i]['movieID'], userReviews[j]['movieID'])
                if key not in graph:
                    graph[key] = 0
                graph[key] += 1
    print(json.dumps(nUsers, sort_keys=True))
    print("Graph generated. Couting %d edges." % len(graph))
    return graph

#users
filename = 'data/users.json'
if(not os.path.isfile(filename)):
    userList = makeUserList()
    print('Generating %s' % filename)
    f = open(filename, 'w')
    json.dump(userList, f, indent=1)
    f.close()
    print('%s generated.' % filename)
else:
    userList = json.load(open(filename))
    print('%s loaded.' % filename)

#graph
filename = 'data/graph.json'
if(not os.path.isfile(filename)):
    edges = makeGraph(userList)
    print('Generating %s' % filename)
    f = open(filename, 'w')
    json.dump(edges, f, indent=1)
    f.close()
    print('%s generated.' % filename)
else:
    userList = json.load(open(filename))
    print('%s loaded.' % filename)


