#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED
#include "queue.h"

class Graph
{
public:
    Graph(int max = 50, int null = 0);
    ~Graph();
    void addVertex(Vertex);
    void addEdge(Vertex, Vertex, int);
    int getWeight(Vertex, Vertex);
    void getAdjacents(Vertex, Queue&);
    void clearMarks();
    void markVertex(Vertex);
    bool isMarked(Vertex);
    void printMatrix();
private:
    int NULL_EDGE; // Constant for null edge
    int maxVertices;
    int numVertices; // Number of added vertices
    Vertex *vertices; // Array with all vertices
    int **edges; // Adjacency matrix
    bool *marks; // marks[i] indicates if vertices[i] has been used
    int getIndex(Vertex);
};

#endif // GRAPH_H_INCLUDED
