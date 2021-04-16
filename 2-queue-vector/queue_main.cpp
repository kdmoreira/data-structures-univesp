#include <iostream>
#include <stdbool.h>
#include "queue.h"
using namespace std;

int main()
{
    // The integer input will be turned into char when displayed
    int input;
    Queue myQueue;
    char charInput;

    do
    {
        cout << "Type a number or -1 to return: ";
        cin >> input;

        if (input != -1)
            myQueue.enqueue(input);

    } while (input != -1 and !myQueue.isFull());

    cout << "Display: ";
    myQueue.display();

    while (!myQueue.isEmpty())
    {
        ItemType dequeued = myQueue.dequeue();
        cout << "Dequeued: " << int(dequeued) << dequeued << endl;
    }
    cin.get();
}
