#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#include "item_type.h"

const int MAX_ITEMS = 100;

class Queue {
public:
    Queue();
    ~Queue();
    bool isEmpty() const;
    bool isFull() const;
    void display() const;
    void enqueue(ItemType);
    ItemType dequeue();
public:
    int front;
    int back;
    ItemType *q;
};

#endif // QUEUE_H_INCLUDED
