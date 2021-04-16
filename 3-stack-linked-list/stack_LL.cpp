#include <iostream>
#include <stdbool.h>
#include <cstddef>
#include <new>
#include "stack.h"
using namespace std;

Stack::Stack()
{
    s = NULL;
}

Stack::~Stack()
{
    Node *temp;
    while (s != NULL)
    {
        temp = s;
        s = s->next;
        delete temp;
    }
}

bool Stack::isEmpty() const
{
    return (s == NULL);
}

bool Stack::isFull() const
{
    Node *temp;
    try
    {
        temp = new Node;
        delete temp;
        return false;
    }
    catch (bad_alloc exception)
    {
        return true;
    }
}

void Stack::display() const
{
    Node *aux = s;
    while (aux)
    {
        cout << aux->data;
        aux = aux->next;
    }
    cout << endl;
}

void Stack::push(ItemType item)
{
    if (isFull())
    {
        throw "Stack is full!";
    }
    else
    {
        Node *aux = new Node;
        aux->data = item;
        aux->next = s;
        s = aux;
    }
}

ItemType Stack::pop()
{
    if (isEmpty())
    {
        throw "Stack is empty!";
    }
    else
    {
        Node *aux = s;
        ItemType data = s->data;
        s = s->next;
        delete aux;
        return data;
    }
}

ItemType Stack::peek(int index) const
{
    if (isEmpty())
    {
        throw "Stack is empty!";
    }
    if (index < 0)
    {
        throw "Invalid index!";
    }
    else
    {
        Node *temp = s;
        for (int i = 0; s != NULL && i < index - 1; i++)
        {
            temp = temp->next;
        }
        return temp->data;
    }
}

ItemType Stack::stackTop() const
{
    if (isEmpty())
    {
        throw "Stack is empty!";
    }
    else
    {
        ItemType aux = s->data;
        return aux;
    }
}
