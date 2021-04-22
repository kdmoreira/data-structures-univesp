#include <iostream>
#include "graph.h"

Graph::Graph(int max, int null_edge)
{
    NULL_EDGE = null_edge;
    maxVertices = max;
    numVertices = 0;
    vertices = new Vertex[maxVertices];
    marks = new bool[maxVertices];
    edges = new int*[maxVertices];

    // Creating adjacency matrix
    for (int row = 0; row < maxVertices; row++)
    {
        edges[row] = new int[maxVertices];
    }

    // Populating adjacency matrix with null values
    for (int row = 0; row < maxVertices; row++)
    {
        for (int col = 0; col < maxVertices; col++)
        {
            edges[row][col] = NULL_EDGE;
        }
    }
}

Graph::~Graph()
{
    delete [] vertices;
    delete [] marks;
    for (int row = 0; row < maxVertices; row++)
    {
        delete [] edges[row];
    }
    delete [] edges;
}

int Graph::getIndex(Vertex vertex)
{
    int index = 0;
    while (!(vertex.getName() == vertices[index].getName()))
    {
        index++;
    }
    return index;
}

void Graph::addVertex(Vertex vertex)
{
    vertices[numVertices] = vertex;
    numVertices++;
}
void Graph::addEdge(Vertex fromVertex, Vertex toVertex, int weight)
{
    int row = getIndex(fromVertex);
    int col = getIndex(toVertex);

    edges[row][col] = weight;
    // Remove if it's a directed graph
    edges[col][row] = weight;
}

int Graph::getWeight(Vertex fromVertex, Vertex toVertex)
{
    int row = getIndex(fromVertex);
    int col = getIndex(toVertex);
    return edges[row][col];
}

void Graph::getAdjacents(Vertex vertex, Queue &adjVertices)
{
    int fromIndex;
    int toIndex;
    fromIndex = getIndex(vertex);
    for (toIndex = 0; toIndex < numVertices; toIndex++)
    if (edges[fromIndex][toIndex] != NULL_EDGE)
    {
        // Adds a copy of the element into the array
        adjVertices.enqueue(vertices[toIndex]);
    }
}

void Graph::clearMarks()
{
    for (int i = 0; i < numVertices; i++)
    {
        marks[i] = false;
    }
}

void Graph::markVertex(Vertex vertex)
{
    int index = getIndex(vertex);
    marks[index] = true;
}

bool Graph::isMarked(Vertex vertex)
{
    int index = getIndex(vertex);
    return marks[index];
}

void Graph::printMatrix()
{
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            std::cout << edges[i][j] << ",";
        }
        std::cout << std::endl;
    }
}
