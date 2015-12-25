/*
文件名: 
描　述: Graph 公共成员函数

作　者: 李肇阳, 清华大学软件学院, lizy14@yeah.net
创建于: 

环　境: Visual Studio 2012 (MSVC++ 11.0)
*/
#include "Graph.h"

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

    for(auto& i : matrixAdjacency){
        i.resize(nVertexes, INFINITY);
    }

    int _1, _2, _3;
    for(int i=0; i<nEdges; i++){
        s >> _1 >> _2 >> _3;
        //undirected edge.
        getWeight(_1, _2) = _3;
        getWeight(_2, _1) = _3;
    }
}
