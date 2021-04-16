#include <iostream>
#include <stdbool.h>
#include "stack.h"
using namespace std;

int main()
{
    Stack myStack;

    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);
    myStack.push(5);

    ItemType popped = myStack.pop();
    cout << popped << " was popped." << endl;

    cout << "Display: ";
    myStack.display();

    cout << "Peek at index 2: " << myStack.peek(2) << endl;

    cout << "StackTop: " << myStack.stackTop() << endl;
}
