#include <iostream>
#include <stdbool.h>
#include "stack.h"
using namespace std;

Stack::Stack()
{
    length = 0;
    s = new ItemType[MAX_ITEMS];
}

Stack::~Stack()
{
    delete [] s;
}

bool Stack::isEmpty() const
{
    return (length == 0);
}

bool Stack::isFull() const
{
    return (length == MAX_ITEMS);
}

void Stack::display() const
{
    for (int i = 0; i < length; i++)
    {
        cout << s[i] << " ";
    }
    cout << endl;
}

void Stack::push(ItemType item)
{
    if (isFull())
    {
        throw "Stack is already full!";
    }
    s[length] = item;
    length++;
}

ItemType Stack::pop()
{
    if (isEmpty())
    {
        throw "Stack is empty!";
    }
    length--;
    ItemType aux = s[length];
    return aux;
}

ItemType Stack::peek(ItemType index) const
{
    if (index < 0 || index > MAX_ITEMS)
    {
        throw "Invalid index!";
    }
    return s[index];
}

ItemType Stack::stackTop() const
{
    if (isEmpty())
    {
        throw "Stack is empty!";
    }
    return s[length - 1];
}

