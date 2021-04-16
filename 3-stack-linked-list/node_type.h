#ifndef NODE_TYPE_H_INCLUDED
#define NODE_TYPE_H_INCLUDED

typedef char ItemType;

struct Node
{
    ItemType data;
    struct Node *next;
};

#endif // NODE_TYPE_H_INCLUDED
