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
#include <map>
#include <algorithm>
#include <iostream>


typedef double weight;  //边权值
typedef int nodeID;  //程序内部的节点标识，范围 [0, n)
typedef int actualID;//用户输入的实际的节点标识，如各种代号、代码，范围远比 [0, n) 宽广

struct Edge{
    nodeID a, b;
    Edge(nodeID a_, nodeID b_):a(a_), b(b_){}
    Edge(){}
};

class Graph{
private:
    int nEdges, nVertexes;
    std::vector<std::vector<weight> > matrixAdjacency; //邻接矩阵
    static const weight INFINITY;

    //translation between actual node identifier and internal nodeID
    nodeID cntAssignedNodes;
    std::vector<actualID> actualNodeID;
    std::map<actualID, nodeID> map;
    


public:
    void insertEdge(actualID start, actualID end, weight w);//takes actual ID, handles translation
    weight& getWeight(nodeID start, nodeID end){
        return matrixAdjacency[start][end];
    }
    void read(std::istream&);
    void printMatrix(std::ostream&);
    Graph():
        nEdges(0),
        nVertexes(0),
        cntAssignedNodes(0){}
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

