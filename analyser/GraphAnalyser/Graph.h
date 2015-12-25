/*
�ļ���: 
�衡��: Graph �ࡣʵ�ַ�ɢ�� Graph.cpp, Prim.cpp, Dijkstra.cpp �С�

������: ������, �廪��ѧ���ѧԺ, lizy14@yeah.net
������: 

������: Visual Studio 2012 (MSVC++ 11.0)
*/

#include <fstream>
#include <vector>
#include <set>
#include <stack>
#include <map>
#include <algorithm>
#include <iostream>


typedef double weight;  //��Ȩֵ
typedef int nodeID;  //�����ڲ��Ľڵ��ʶ����Χ [0, n)
typedef int actualID;//�û������ʵ�ʵĽڵ��ʶ������ִ��š����룬��ΧԶ�� [0, n) ���

struct Edge{
    nodeID a, b;
    Edge(nodeID a_, nodeID b_):a(a_), b(b_){}
    Edge(){}
};

class Graph{
private:
    int nEdges, nVertexes;
    std::vector<std::vector<weight> > matrixAdjacency; //�ڽӾ���
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




    //Prim����С������
private:
    std::set<weight> V;//���ѷ��룩��С�������еĶ���
    std::vector<Edge> T;//���ѷ��룩��С�������еı�
    void prim();
    void printTree(std::ostream&);
public:
    void printMinimalSpanningTree(std::ostream& s);



    //Dijkstra����Դ���·��
private:
    std::vector<nodeID> Q;//��Դ���·����Ϣ
    std::vector<weight> pi;//��Դ���·���ĳ���
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

