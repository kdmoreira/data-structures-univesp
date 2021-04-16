#include <iostream>
#include <stdbool.h>
#include "stack.h"
using namespace std;

int main()
{
    Stack myStack;
    ItemType word;
    ItemType popped;

    cout << "Type a word: ";
    cin.get(word);

    while (word != '\n')
    {
        myStack.push(word);
        cin.get(word);
    }

    cout << "Display in correct order: ";
    myStack.display();

    cout << "StackTop: " << myStack.stackTop() << endl;

    cout << "Display in inverse order: ";
    while (!myStack.isEmpty())
    {
        popped = myStack.pop();
        cout << popped << " ";
    }
    cout << endl;

    cout << "Peek at index 2: " << myStack.peek(2) << endl;
}
