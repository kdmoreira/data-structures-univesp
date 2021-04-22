#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#include "node_type.h"

class Queue {
public:
    Queue();
    ~Queue();
    bool isEmpty() const;
    bool isFull() const;
    void display() const;
    void enqueue(ItemType);
    ItemType dequeue();
private:
    Node *front;
    Node *back;
};

#endif // QUEUE_H_INCLUDED
