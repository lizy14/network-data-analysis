/*
文件名: 
描　述: Dijkstra 算法求正权无向图中某点到其他点之间的最短路径
　　　  采用邻接矩阵表示图

作　者: 李肇阳, 清华大学软件学院, lizy14@yeah.net
创建于: 

环　境: Visual Studio 2012 (MSVC++ 11.0)
*/


#include "Graph.h"

void Graph::dijkstra(nodeID startingPoint_){
    startingPoint = startingPoint_;

    std::set<nodeID> T;
    for(int i=0; i<nVertexes; i++){
        if(i!=startingPoint)
            T.insert(i);
    }

    pi.resize(nVertexes);
    for(int i=0; i<nVertexes; i++){
        pi[i]=getWeight(startingPoint,i);
    }
    Q.clear();
    Q.resize(nVertexes, startingPoint);

    //initialization done. here comes the main loop

    while(T.size()!=0){
        //find the node inside T with minimal pi
        int minPi = INFINITY;
        int minID = *T.begin();

        for(auto& i: T){
            if(pi[i]<minPi){
                minID = i;
                minPi = pi[i];
            }
        }

        //found it.
        T.erase(T.find(minID));


        //modify T and Q
        for(auto& i: T){
            weight possibleNewPi = pi[minID] + getWeight(minID, i);
            if(possibleNewPi < pi[i]){
                pi[i]=possibleNewPi;
                Q[i] = minID;
            }
        }
    }

    return;
}

std::vector<nodeID> Graph::getPath(nodeID destination){
    std::vector<nodeID> vector;
    std::stack<nodeID> stack;

    nodeID p = destination;
    while(Q[p]!=startingPoint){
        stack.push(Q[p]);
        p = Q[p];
    }
    while(!stack.empty()){
        vector.push_back(stack.top());
        stack.pop();
    }
    return vector;
}

void Graph::printAllShortestPaths(std::ostream& s){

    for(int j=0; j<nVertexes; j++){
        int startingPoint = j;
        dijkstra(startingPoint);
        for(int i=0; i<nVertexes; i++){
            if(i<=j) continue;

            int endingPoint = i;
            s << nodeIDTranslation(j) << "-" << nodeIDTranslation(i) << ": ";
            weight length = getPathLength(endingPoint);
            if(length>=Graph::INFINITY){
                s << "NO PATH\n";
                continue;
            }
            s << length << ", ";
            s << nodeIDTranslation(startingPoint) << "-";
            std::vector<int> path = getPath(endingPoint);
            for(auto i : path){
                s << nodeIDTranslation(i) << '-';
            }
            s << nodeIDTranslation(endingPoint) << '\n';
        }
    }
}
