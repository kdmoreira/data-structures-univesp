#include "avl_tree.h"
using namespace std;

const int NUM_ALUNOS = 15;

int main()
{
    AVLTree avlTree;

    int ras[NUM_ALUNOS] = {41, 27, 74, 4, 29, 65, 90, 2, 6, 28, 30, 60, 73, 80, 92};

    string names[NUM_ALUNOS] = {"Enelton", "Cristhof", "Danielle", "Meira", "Guilherme", "Juliana",
    "Pedro", "Raul", "Paulo", "Carlos", "Lucas", "Maria", "Samanta", "Ulisses", "Carlos"};

    Aluno alunos[NUM_ALUNOS];

    for (int i = 0; i < NUM_ALUNOS; i++)
    {
        Aluno aluno = Aluno(ras[i], names[i]);
        alunos[i] = aluno;
        avlTree.insertAluno(aluno);
    }

    cout << "Pre: ";
    avlTree.printPreOrder();
    cout << endl;

    cout << "In: ";
    avlTree.printInOrder();
    cout << endl;

    cout << "Post: ";
    avlTree.printPostOrder();
    cout << endl;

    avlTree.deleteAluno(alunos[0].getRa());
    avlTree.deleteAluno(alunos[11].getRa());
    avlTree.deleteAluno(alunos[5].getRa());
    avlTree.deleteAluno(alunos[12].getRa());

    cout << "********" << endl;
    cout << "Pre: ";
    avlTree.printPreOrder();
    cout << endl;

    cout << "In: ";
    avlTree.printInOrder();
    cout << endl;

    cout << "Post: ";
    avlTree.printPostOrder();
    cout << endl;
}
