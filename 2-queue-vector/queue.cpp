#include <iostream>
#include <stdbool.h>
#include "queue.h"
using namespace std;

Queue::Queue()
{
    front = 0;
    back = 0;
    q = new ItemType[MAX_ITEMS];
}

Queue::~Queue()
{
    delete [] q;
}

bool Queue::isEmpty() const
{
    return (front == back);
}

bool Queue::isFull() const
{
    return (back - front == MAX_ITEMS);
}

void Queue::display() const
{
    for (int i = front; i < back; i++)
    {
        cout << q[i % MAX_ITEMS] << " ";
    }
    cout << endl;
}

void Queue::enqueue(ItemType item)
{
    if (isFull())
    {
        throw "Queue is full!";
    }
    q[back % MAX_ITEMS] = item;
    back++;
}

ItemType Queue::dequeue()
{
    if (isEmpty())
    {
        throw "Queue is empty!";
    }
    front++;
    return q[(front - 1) % MAX_ITEMS];
}
