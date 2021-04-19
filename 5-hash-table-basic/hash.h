#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED
#include "aluno.h"

class Hash {
public:
    Hash(int max_items);
    ~Hash();
    bool isFull() const;
    int getLength() const;
    void retrieveItem(Aluno &aluno, bool &found);
    void insertItem(Aluno aluno);
    void deleteItem(Aluno aluno);
    void print();
private:
    int getHash(Aluno aluno);
    int max_items;
    int length;
    Aluno *H;
};

#endif // HASH_H_INCLUDED
