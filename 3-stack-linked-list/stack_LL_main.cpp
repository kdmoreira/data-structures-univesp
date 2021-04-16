#include <iostream>
#include "stack.h"
using namespace std;

int main()
{
    // Verifies if an expression is well-formed
    Stack myStack;
    ItemType word;

    cout << "Type an expression: ";
    cin.get(word);

    bool isMatched = true;
    while (isMatched && word != '\n')
    {
        if (word == '(' || word == '{' ||
            word == '[')
        {
            myStack.push(word);
        }
        if (word == ')' || word == '}' ||
            word == ']')
        {
            if (myStack.isEmpty())
            {
                isMatched = false;
            }
            else
            {
                ItemType item = myStack.pop();
                isMatched = ((word == ')' && item == '(') ||
                            (word == '}' && item == '{') ||
                            (word == ']' && item == '['));
            }
        }
        cin.get(word);
    }

    if (isMatched && myStack.isEmpty())
    {
        cout << "The expression is well-formed.";
    }
    else
    {
        cout << "The expression isn't well-formed.";
    }
}
