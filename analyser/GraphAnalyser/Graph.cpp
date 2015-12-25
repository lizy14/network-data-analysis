/*
文件名: 
描　述: Graph 公共成员函数

作　者: 李肇阳, 清华大学软件学院, lizy14@yeah.net
创建于: 

环　境: Visual Studio 2012 (MSVC++ 11.0)
*/
#include "Graph.h"
void Graph::insertEdge(actualID start, actualID end, weight w){
    //modifies `actualNodeID[]`, `cntAssignedNodes`, `matrixAdjacency[][]`
    int startID, endID;

    auto startIt = map.find(start);
    if(startIt == map.end()){
        actualNodeID[cntAssignedNodes] = start;
        startID  = cntAssignedNodes;
        map[start] = cntAssignedNodes++;
    }else{
        startID = startIt->second;
    }
    auto endIt = map.find(end);
    if(endIt == map.end()){
        actualNodeID[cntAssignedNodes] = end;
        endID = cntAssignedNodes;
        map[end] = cntAssignedNodes++;
    }else{
        endID = endIt->second;
    }
    matrixAdjacency[startID][endID] = w;
    matrixAdjacency[endID][startID] = w;
    return;
}
void Graph::printMatrix(std::ostream& s){
    s << "Matrix" << std::endl;
    for(int i=0; i<nVertexes; i++){
        for(int j=0; j<nVertexes; j++){
            s << matrixAdjacency[i][j] <<' ';
        }
        s << std::endl;
    }
}

void Graph::read(std::istream& s){
    s >> nVertexes >> nEdges;

    //make an n*n matrix
    matrixAdjacency.resize(nVertexes);
    actualNodeID.resize(nVertexes);

    for(auto& i : matrixAdjacency){
        i.resize(nVertexes, INFINITY);
    }

    int _1, _2, _3;
    for(int i=0; i<nEdges; i++){
        s >> _1 >> _2 >> _3;
        insertEdge(_1,_2,_3);
    }
}
