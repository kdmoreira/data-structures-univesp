#ifndef AVL_TREE_H_INCLUDED
#define AVL_TREE_H_INCLUDED
#include <cstddef>
#include <iostream>
#include "aluno.h"

struct Node
{
    Aluno aluno;
    int BFactor;
    Node *left;
    Node *right;
};

class AVLTree
{
public:
    AVLTree() { root = NULL; }
    ~AVLTree() { destroyTree(root); }
    bool isEmpty() const;
    bool isFull() const;
    void retrieveAluno(Aluno &item, bool &found) const {
        retrieveAluno(root, item, found);
    }
    void insertAluno(Aluno item){
        bool isTaller;
        insertAluno(root, item, isTaller);
    }
    void deleteAluno(int item){
        bool isShorter;
        deleteAluno(root, item, isShorter);
    }
    void printPreOrder() const { printPreOrder(root); }
    void printInOrder() const { printInOrder(root); }
    void printPostOrder() const { printPostOrder(root); }

private:
    void destroyTree(Node *&tree);
    void retrieveAluno(Node *tree, Aluno &item, bool &found) const;
    void insertAluno(Node *&tree, Aluno item, bool &isTaller);
    void deleteAluno(Node *&tree, int item, bool &isShorter);
    void deleteNode(Node *&tree, bool &isShorter);
    void getSuccessor(Node *tree, Aluno &data);
    void printTree(Node *tree) const;
    void printPreOrder(Node *tree) const;
    void printInOrder(Node *tree) const;
    void printPostOrder(Node *tree) const;
    void rotateToLeft(Node *&tree) const;
    void rotateToRight(Node *&tree) const;
    void rotateToLeftAndRight(Node *&tree) const;
    void rotateToRightAndLeft(Node *&tree) const;
    void performRotations(Node *&tree) const;

    Node *root;
};

#endif // AVL_TREE_H_INCLUDED
