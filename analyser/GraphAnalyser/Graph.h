/*
文件名: 
描　述: Graph 类。实现分散于 Graph.cpp, Prim.cpp, Dijkstra.cpp 中。

作　者: 李肇阳, 清华大学软件学院, lizy14@yeah.net
创建于: 

环　境: Visual Studio 2012 (MSVC++ 11.0)
*/

#include <fstream>
#include <vector>
#include <set>
#include <stack>
#include <algorithm>
#include <iostream>


typedef int weight;
typedef int nodeID;

struct Edge{
    nodeID a, b;
    Edge(nodeID a_, nodeID b_):a(a_), b(b_){}
    Edge(){}
};

class Graph{
private:
    int nEdges, nVertexes;
    std::vector<std::vector<weight> > matrixAdjacency; //邻接矩阵
public:
    static const weight INFINITY = 1000000/2;



public:
    weight& getWeight(nodeID start, nodeID end){
        return matrixAdjacency[start][end];
    }
    void read(std::istream&);
    void printMatrix(std::ostream&);
    Graph():
        nEdges(0),
        nVertexes(0){}
    ~Graph(){}




    //Prim：最小生成树
private:
    std::set<weight> V;//（已放入）最小生成树中的顶点
    std::vector<Edge> T;//（已放入）最小生成树中的边
    void prim();
    void printTree(std::ostream&);
public:
    void printMinimalSpanningTree(std::ostream& s);



    //Dijkstra：单源最短路径
private:
    std::vector<nodeID> Q;//单源最短路径信息
    std::vector<weight> pi;//单源最短路径的长度
    nodeID startingPoint;
public:
    //calls `dijkstra()` n times, print n*(n-1)/2 paths.
    void printAllShortestPaths(std::ostream&);    
    void dijkstra(nodeID);
    std::vector<nodeID> getPath(nodeID destination);
    weight getPathLength(nodeID destination){
        if(destination==startingPoint)
            return 0;
        return pi[destination];
    }


};

