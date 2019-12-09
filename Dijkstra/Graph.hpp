#ifndef GRAPH_HPP_
#define GRAPH_HPP_
#include <iostream>
#include <stdlib.h>
using namespace std;

class Graph {
    int **adjMatrix;
    int numOfVerts;
    itn start;
    string *dataArr;
    //BinHeap priorityQueue();
    bool *visited;
    int *distances;
    int *prev;
    public:
        Graph(int n, int first, string vertexnames[]);
        void dijkstra();
        void setDistances(int lv);
        void printAdjMatrix();
        void printInfoSoFar();
        void printPath(int end);
        void genGraph();
};
#endif /*GRAPH_HPP_ */