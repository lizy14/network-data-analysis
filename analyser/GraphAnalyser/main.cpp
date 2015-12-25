/*
�ļ���: main.cpp
�衡��: ��ڵ㣺ͼ������

������: ������, �廪��ѧ���ѧԺ, lizy14@yeah.net
������: 2015-11-02

������: Visual Studio 2012 (MSVC++ 11.0)
*/

#include <iostream>
#include <fstream>
#include "Graph.h"

using namespace std;

int test(std::istream& s){
    Graph graph;
    graph.read(s);


    cout << "Minimal spanning tree:\n";
    graph.printMinimalSpanningTree(std::cout);

    cout << "Shortest path:\n";
    graph.printAllShortestPaths(std::cout);

    return 0;
}
int main(){
    std::ifstream file("input.txt");
    return test(file) || system("pause");
}