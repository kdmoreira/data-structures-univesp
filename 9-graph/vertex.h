#ifndef VERTEX_H_INCLUDED
#define VERTEX_H_INCLUDED
#include <iostream>

class Vertex
{
public:
    Vertex() { this->name = ""; }
    Vertex(std::string name) { this->name = name; }
    std::string getName() const { return name; };
private:
    std::string name;
};

#endif // VERTEX_H_INCLUDED
