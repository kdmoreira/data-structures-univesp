#include <iostream>
#include "hash.h"
using namespace std;

Hash::Hash(int max_items)
{
    this->max_items = max_items;
    this->length = 0;
    this->H = new Aluno[max_items];
}

Hash::~Hash()
{
    delete [] H;
}

bool Hash::isFull() const
{
    return (length == max_items);
}

int Hash::getLength() const
{
    return length;
}

int Hash::getHash(Aluno aluno)
{
    return aluno.getRa() % max_items;
}

void Hash::retrieveItem(Aluno &aluno, bool &found)
{
    int startIndex = getHash(aluno);
    bool searchMore = true;
    int location = startIndex;

    do
    {
        if (H[startIndex].getRa() == aluno.getRa() || H[startIndex].getRa() == -1)
        {
            searchMore = false;
        }
        else
        {
            location = (location + 1) % max_items;
        }
    } while (startIndex != location && searchMore);

    found = (H[location].getRa() == aluno.getRa());

    if (found)
    {
        aluno = H[location];
    }

}

void Hash::insertItem(Aluno aluno)
{
    int index = getHash(aluno);
    while (H[index].getRa() > 0)
    {
        index = (index + 1) % max_items;
    }
    H[index] = aluno;
    length++;
}

void Hash::deleteItem(Aluno aluno)
{
    int startIndex = getHash(aluno);
    bool searchMore = true;
    int location = startIndex;

    do
    {
        if (H[location].getRa() == aluno.getRa() || H[location].getRa() == -1)
        {
            searchMore = false;
        }
        else
        {
            location = (location + 1) % max_items;
        }
    } while (location != startIndex && searchMore);

    if (H[location].getRa() == aluno.getRa())
    {
        // -2 indicates an item has been deleted and it won't stop a further search
        H[location] = Aluno(-2,"");
        length--;
    }
}

void Hash::print()
{
    for (int i = 0; i < max_items; i++)
    {
        cout << i << ": " << H[i].getRa() << ", " << H[i].getNome() << endl;
    }
}
