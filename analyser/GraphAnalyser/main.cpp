/*
文件名: main.cpp
描　述: 入口点：图分析器

作　者: 李肇阳, 清华大学软件学院, lizy14@yeah.net
创建于: 2015-11-02

环　境: Visual Studio 2012 (MSVC++ 11.0)
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include "Graph.h"

using namespace std;
#define DEBUG_TIMING
int test(std::istream& ins, std::ostream& outs){

    outs << setprecision(10);

    cout << "Loading graph...\n";

    Graph graph;
    graph.read(ins);


    cout << "Generating minimal spanning tree...\n";

    outs << "Minimal spanning tree:\n";
    graph.printMinimalSpanningTree(outs);
    

    cout << "Calculating shortest graph...\n";

    outs << "Shortest path:\n";
    graph.printAllShortestPaths(outs);
    

    cout << "Printing translation...\n";

    outs << "Node ID translation:\n";
    graph.printTranslationTable(outs);

    cout << "All done.\n";

    return 0;
}
int main(){
    std::ifstream infile("input.txt");
    if(!infile)
        return cout << "Error opening `input.txt`!", -1;
    std::ofstream outfile("output.txt");
    if(!outfile)
        return cout << "Error opening `output.txt`!", -1;

    return test(infile, outfile) || system("pause");
}