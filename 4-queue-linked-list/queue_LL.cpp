#include <iostream>
#include <cstddef>
#include <new>
#include "queue.h"
using namespace std;

Queue::Queue()
{
    front = NULL;
    back = NULL;
}

Queue::~Queue()
{
    Node *temp = NULL;
    while (front)
    {
        temp = front;
        front = front->next;
        delete temp;
    }
    back = NULL;
}

bool Queue::isFull() const
{
    Node *aux;
    try
    {
        aux = new Node;
        delete aux;
        return false;
    }
    catch (bad_alloc exception)
    {
        return true;
    }
}

bool Queue::isEmpty() const
{
    return (front == NULL);
}

void Queue::display() const
{
    Node *aux = front;
    while (aux)
    {
        cout << aux->data;
        aux = aux->next;
    }
    cout << endl;
}

void Queue::enqueue(ItemType item)
{
    if (isFull())
    {
        throw "Queue is full!";
    }
    Node *aux = new Node;
    aux->data = item;
    aux->next = NULL;

    if (back == NULL)
    {
        front = aux;
    }
    else
    {
        back->next = aux;
    }
    back = aux;
}

ItemType Queue::dequeue()
{
    if (isEmpty())
    {
        throw "Queue is empty!";
    }
    Node *temp = front;
    ItemType dequeued = front->data;
    front = front->next;
    if (front == NULL)
    {
        back = NULL;
    }
    delete temp;
    return dequeued;
}
