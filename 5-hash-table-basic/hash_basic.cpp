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
    int index = getHash(aluno);
    Aluno aux = H[index];
    if (aluno.getRa() == aux.getRa())
    {
        found = false;
    }
    else
    {
        found = true;
        aluno = aux;
    }
}

void Hash::insertItem(Aluno aluno)
{
    int index = getHash(aluno);
    H[index] = aluno;
    length++;
}

void Hash::deleteItem(Aluno aluno)
{
    int index = getHash(aluno);
    H[index] = Aluno();
    length--;
}

void Hash::print()
{
    for (int i = 0; i < max_items; i++)
    {
        cout << i << ": " << H[i].getRa() << ", " << H[i].getNome() << endl;
    }
}
