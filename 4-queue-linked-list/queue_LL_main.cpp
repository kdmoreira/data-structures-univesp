#include <iostream>
#include <stdbool.h>
#include "queue.h"
#include "stack.h"
using namespace std;

int main()
{
    Queue myQueue;
    Stack myStack;

    bool palindrome = true;

    char queueChar;
    char stackChar;
    char character;

    cout << "Type a word: ";
    cin.get(character);

    while(character != '\n')
    {
        myQueue.enqueue(character);
        myStack.push(character);
        cin.get(character);
    }

    while (palindrome && !myQueue.isEmpty())
    {
        queueChar = myQueue.dequeue();
        stackChar = myStack.pop();
        if (stackChar != queueChar)
        {
            palindrome = false;
        }
    }

    if (palindrome)
    {
        cout << "The word is a palindrome.";
    }
    else
    {
        cout << "The word isn't a palindrome.";
    }

    return 0;
}

