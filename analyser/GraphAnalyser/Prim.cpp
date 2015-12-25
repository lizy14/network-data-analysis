/*
文件名: 
描　述: Prim 算法寻找无向图的一棵最小生成树

作　者: 李肇阳, 清华大学软件学院, lizy14@yeah.net
创建于: 2015-12-07

环　境: Visual Studio 2012 (MSVC++ 11.0)
*/
#include "Graph.h"

bool operator<(Edge x, Edge y){
    if(x.a < y.a)
        return true;
    else if(x.a == y.a)
        return x.b < y.b;
    else 
        return false;
}

void Graph::prim(){
    V.clear();
    T.clear();

    V.insert(0);
    while(V.size()!=nVertexes){
        nodeID a, b;
        weight shortestEdge = -1;
        for(int i=0; i<nVertexes; i++){
            if(V.find(i)==V.end())
                continue;
            //i is in V
            for(int j=0; j<nVertexes; j++){
                if(V.find(j)!=V.end())
                    continue;
                if(i==j)
                    continue;
                //now nodeID i is in V, while j is not
                weight distance = getWeight(i, j);
                if(distance <shortestEdge || shortestEdge == -1){
                    a = i, b = j;
                    shortestEdge = distance;
                }
            }
        }
        T.push_back(Edge(a, b));
        V.insert(b);

    }
}

void Graph::printTree(std::ostream& s){
    weight total = 0;
    for(auto i : T){
        total += getWeight(i.a, i.b);
        if(i.a > i.b){
            nodeID t;
            t = i.a, i.a = i.b, i.b = t;
        }
    }

    std::sort(T.begin(), T.end());
    s << total << '\n';
    for(auto i : T){
        s << actualNodeID[i.a] << '-' << actualNodeID[i.b] << ' ';
    }
    s << '\n';
}

void Graph::printMinimalSpanningTree(std::ostream& s){
    prim();
    printTree(s);
}