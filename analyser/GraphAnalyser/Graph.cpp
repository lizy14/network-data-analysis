/*
�ļ���: 
�衡��: Graph ������Ա����

������: ������, �廪��ѧ���ѧԺ, lizy14@yeah.net
������: 

������: Visual Studio 2012 (MSVC++ 11.0)
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
