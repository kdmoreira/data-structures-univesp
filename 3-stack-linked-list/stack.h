#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include "node_type.h"

class Stack {
public:
    Stack();
    ~Stack();
    bool isFull() const;
    bool isEmpty() const;
    void display() const;
    void push(ItemType);
    ItemType pop();
    ItemType peek(int) const;
    ItemType stackTop() const;
private:
    Node *s;
};

#endif // STACK_H_INCLUDED
