#ifndef NODE_TYPE_H_INCLUDED
#define NODE_TYPE_H_INCLUDED
#include "vertex.h"

typedef Vertex ItemType;

struct Node
{
    ItemType data;
    Node *next;
};
#endif // NODE_TYPE_H_INCLUDED
