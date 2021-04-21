#include "search_tree.h"

bool SearchTree::isEmpty() const
{
    return (root == NULL);
}

bool SearchTree::isFull() const
{
    Node *temp;
    try
    {
        temp = new Node;
        delete temp;
        return false;
    }
    catch(bad_alloc exception)
    {
        return true;
    }
}

void SearchTree::destroyTree(Node *&tree)
{
    if (tree)
    {
        destroyTree(tree->left);
        destroyTree(tree->right);
        delete tree;
    }
}

void SearchTree::retrieveAluno(Node *tree, Aluno &aluno, bool& found) const
{
    if (tree == NULL)
    {
        found = false;
    }
    else if (aluno.getRa() < tree->aluno.getRa())
    {
        retrieveAluno(tree->left, aluno, found);
    }
    else if (aluno.getRa() > tree->aluno.getRa())
    {
        retrieveAluno(tree->right, aluno, found);
    }
    else
    {
        aluno = tree->aluno;
        found = true;
    }
}

void SearchTree::insertAluno(Node *&tree, Aluno aluno)
{
    if (tree == NULL)
    {
        tree = new Node;
        tree->right = NULL;
        tree->left = NULL;
        tree->aluno = aluno;
    }
    else if (aluno.getRa() < tree->aluno.getRa())
    {
        insertAluno(tree->left, aluno);
    }
    else
    {
        insertAluno(tree->right, aluno);
    }
}

void SearchTree::deleteAluno(Node *&tree, int aluno)
{
    if (aluno < tree->aluno.getRa() )
    {
        deleteAluno(tree->left, aluno);
    }
    else if (aluno > tree->aluno.getRa())
    {
        deleteAluno(tree->right, aluno);
    }
    else if (aluno == tree->aluno.getRa())
    {
        deleteNode(tree);
    }
}

void SearchTree::deleteNode(Node *&tree)
{
    Aluno data;
    Node *tempPtr;
    tempPtr = tree;
    if (tree->left == NULL)
    {
        tree = tree->right;
        delete tempPtr;
    }
    else if (tree->right == NULL)
    {
        tree = tree->left;
        delete tempPtr;
    }
    else
    {
        getSuccessor(tree, data);
        tree->aluno = data;
        deleteAluno(tree->right, data.getRa());
    }
}

void SearchTree::getSuccessor(Node *tree, Aluno &data)
{
    tree = tree->right;
    while (tree->left != NULL)
    {
        tree = tree->left;
    }
    data = tree->aluno;
}

void SearchTree::printPreOrder(Node *tree) const
{
    if (tree != NULL)
    {
        std::cout << tree->aluno.getNome() << " , ";
        printPreOrder(tree->left);
        printPreOrder(tree->right);
    }
}

void SearchTree::printInOrder(Node *tree) const
{
    if (tree != NULL)
    {
        printInOrder(tree->left);
        std::cout << tree->aluno.getNome() << " , ";
        printInOrder(tree->right);
    }
}

void SearchTree::printPostOrder(Node *tree) const
{
    if (tree != NULL)
    {
        printPostOrder(tree->left);
        printPostOrder(tree->right);
        std::cout << tree->aluno.getNome() << " , ";
    }
}
