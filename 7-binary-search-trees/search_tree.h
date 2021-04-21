#ifndef SEARCH_TREE_H_INCLUDED
#define SEARCH_TREE_H_INCLUDED
#include <cstddef>
#include <iostream>
#include "aluno.h"

struct Node
{
    Aluno aluno;
    Node *left;
    Node *right;
};

class SearchTree
{
public:
    SearchTree() { root = NULL; }
    ~SearchTree() { destroyTree(root); }
    bool isEmpty() const;
    bool isFull() const;
    void retrieveAluno(Aluno &item, bool &found) const {
        retrieveAluno(root, item, found);
    }
    void insertAluno(Aluno item){ insertAluno(root, item); }
    void deleteAluno(int item){ deleteAluno(root, item); }
    void printPreOrder() const { printPreOrder(root); }
    void printInOrder() const { printInOrder(root); }
    void printPostOrder() const { printPostOrder(root); }
private:
    void destroyTree(Node *&tree);
    void retrieveAluno(Node *tree, Aluno &item, bool &found) const;
    void insertAluno(Node *&tree, Aluno item);
    void deleteAluno(Node *&tree, int item);
    void deleteNode(Node *&tree);
    void getSuccessor(Node *tree, Aluno &data);
    void printTree(Node *tree) const;
    void printPreOrder(Node *tree) const;
    void printInOrder(Node *tree) const;
    void printPostOrder(Node *tree) const;

    Node *root;
};

#endif // SEARCH_TREE_H_INCLUDED
