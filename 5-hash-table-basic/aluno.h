#ifndef ALUNO_H_INCLUDED
#define ALUNO_H_INCLUDED
#include <iostream>
using namespace std;

class Aluno {
public:
    int ra;
    string nome;
public:
    Aluno();
    Aluno(int ra, string nome);
    string getNome() const;
    int getRa() const;
};

#endif // ALUNO_H_INCLUDED
