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
#define DEBUG_TIMING
int test(std::istream& ins, std::ostream& outs){
#ifdef DEBUG_TIMING
    system("PrintDateAndTime");
#endif
    cout << "Loading graph...";

    Graph graph;
    graph.read(ins);

#ifdef DEBUG_TIMING
    system("PrintDateAndTime");
#endif
    cout << "Generating minimal spanning tree...";

    outs << "Minimal spanning tree:\n";
    graph.printMinimalSpanningTree(outs);
    
#ifdef DEBUG_TIMING
    system("PrintDateAndTime");
#endif
    cout << "Calculating shortest graph...";

    outs << "Shortest path:\n";
    graph.printAllShortestPaths(outs);

#ifdef DEBUG_TIMING
    system("PrintDateAndTime");
#endif
    cout << "All done.";

    return 0;
}
int main(){
    std::ifstream infile("input.txt");
    std::ofstream outfile("output.txt");
    return test(infile, outfile) || system("pause");
}