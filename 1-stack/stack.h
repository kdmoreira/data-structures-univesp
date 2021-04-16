#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#include "item_type.h"

const int MAX_ITEMS = 100;

class Stack {
public:
    Stack();
    ~Stack();
    bool isEmpty() const;
    bool isFull() const;
    void display() const;
    void push(ItemType);
    ItemType pop();
    ItemType peek(ItemType) const;
    ItemType stackTop() const;
private:
    int length;
    ItemType *s;
};

#endif // STACK_H_INCLUDED
