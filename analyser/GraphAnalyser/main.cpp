/*
文件名: main.cpp
描　述: 入口点：图分析器

作　者: 李肇阳, 清华大学软件学院, lizy14@yeah.net
创建于: 2015-11-02

环　境: Visual Studio 2012 (MSVC++ 11.0)
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