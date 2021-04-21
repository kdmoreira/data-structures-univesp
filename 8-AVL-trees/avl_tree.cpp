#include "avl_tree.h"

bool AVLTree::isEmpty() const
{
    return (root == NULL);
}

bool AVLTree::isFull() const
{
    Node *temp;
    try
    {
        temp = new Node;
        delete temp;
        return false;
    }
    catch(std::bad_alloc exception)
    {
        return true;
    }
}

void AVLTree::destroyTree(Node *&tree)
{
    if (tree)
    {
        destroyTree(tree->left);
        destroyTree(tree->right);
        delete tree;
    }
}

void AVLTree::retrieveAluno(Node *tree, Aluno &aluno, bool &found) const
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

void AVLTree::insertAluno(Node *&tree, Aluno aluno, bool &isTaller)
{
    if (tree == NULL)
    {
        tree = new Node;
        tree->aluno = aluno;
        tree->left = NULL;
        tree->right = NULL;
        tree->BFactor = 0;
        isTaller = true;
        return;
    }
    if (aluno.getRa() < tree->aluno.getRa())
    {
        insertAluno(tree->left, aluno, isTaller);
        if (isTaller)
        {
            tree->BFactor = tree->BFactor - 1;
        }
    }
    else
    {
        insertAluno(tree->right, aluno, isTaller);
        if (isTaller)
        {
            tree->BFactor= tree->BFactor + 1;
        }
    }
    performRotations(tree);

    if (isTaller && tree->BFactor == 0)
    {
        isTaller = false;
    }
}

void AVLTree::deleteAluno(Node *&tree, int aluno, bool &isShorter)
{
    if (aluno < tree->aluno.getRa())
    {
        deleteAluno(tree->left, aluno, isShorter);
        if (isShorter)
        {
            tree->BFactor = tree->BFactor + 1;
        }
    }
    else if (aluno > tree->aluno.getRa())
    {
        deleteAluno(tree->right, aluno, isShorter);
        if (isShorter)
        {
            tree->BFactor = tree->BFactor - 1;
        }
    }
    else if (aluno == tree->aluno.getRa())
    {
        deleteNode(tree, isShorter);
    }
    if (tree != NULL)
    {
        performRotations(tree);
        if (isShorter && tree->BFactor != 0)
        {
            isShorter = false;
        }
    }
}

void AVLTree::deleteNode(Node *&tree, bool &isShorter)
{
    Aluno data;
    Node *tempPtr;
    tempPtr = tree;
    if (tree->left == NULL)
    {
        tree = tree->right;
        isShorter = true;
        delete tempPtr;
    }
    else if (tree->right == NULL)
    {
        tree = tree->left;
        isShorter = true;
        delete tempPtr;
    }
    else
    {
        getSuccessor(tree, data);
        tree->aluno = data;
        deleteAluno(tree->right, data.getRa(), isShorter);
        if (isShorter)
        {
            tree->BFactor = tree->BFactor - 1;
        }
    }
}

void AVLTree::getSuccessor(Node *tree, Aluno &data)
{
    tree = tree->right;
    while (tree->left != NULL)
    {
        tree = tree->left;
    }
    data = tree->aluno;
}

void AVLTree::printPreOrder(Node *tree) const
{
    if (tree)
    {
        std::cout << tree->aluno.getNome() << "[" << tree->BFactor << "] ";
        printPreOrder(tree->left);
        printPreOrder(tree->right);
    }
}

void AVLTree::printInOrder(Node *tree) const
{
    if (tree)
    {
        printPreOrder(tree->left);
        std::cout << tree->aluno.getNome() << "[" << tree->BFactor << "] ";
        printPreOrder(tree->right);
    }
}

void AVLTree::printPostOrder(Node *tree) const
{
    if (tree)
    {
        printPreOrder(tree->left);
        printPreOrder(tree->right);
        std::cout << tree->aluno.getNome() << "[" << tree->BFactor << "] ";
    }
}

void AVLTree::rotateToLeft(Node *&tree) const
{
      Node *p = tree->right;
      tree->right = p->left;
      p->left = tree;
      tree = p;
}

void AVLTree::rotateToRight(Node *&tree) const
{
      Node *p = tree->left;
      tree->left = p->right;
      p->right = tree;
      tree = p;
}

void AVLTree::rotateToLeftAndRight(Node *&tree) const
{
    Node *child = tree->left;
    rotateToLeft(child);
    tree->left = child;
    rotateToRight(tree);
}

void AVLTree::rotateToRightAndLeft(Node *&tree) const
{
    Node *child = tree->right;
    rotateToLeft(child);
    tree->right = child;
    rotateToRight(tree);
}

void AVLTree::performRotations(Node *&tree) const
{
    Node *child;
    Node *grandChild;

    if (tree->BFactor == -2)
    {
        child = tree->left;

        // Right rotation
        switch(child->BFactor)
        {
        case -1:
            tree->BFactor = 0;
            child->BFactor = 0;
            rotateToRight(tree);
            break;
        case 0:
            tree->BFactor = -1;
            child->BFactor = +1;
            rotateToRight(tree);
            break;
        case 1:
            grandChild = child->right;

            switch(grandChild->BFactor)
            {
            case -1:
                tree->BFactor = +1;
                child->BFactor = 0;
                break;
            case 0:
                tree->BFactor = 0;
                child->BFactor =  0;
                break;
            case +1:
                tree->BFactor = 0;
                child->BFactor = -1;
                break;
            }
            grandChild->BFactor = 0;
            rotateToLeftAndRight(tree);
        }
    }

    else if (tree->BFactor == +2)
    {
        child = tree->right;

        // Left rotation
        switch(child->BFactor)
        {
        case 1:
            tree->BFactor = 0;
            child->BFactor = 0;
            rotateToLeft(tree);
            break;
        case 0:
            tree->BFactor = +1;
            child->BFactor = -1;
            rotateToLeft(tree);
            break;
        case -1:
            grandChild = child->left;

            switch(grandChild->BFactor)
            {
            case -1:
                tree->BFactor = 0;
                child->BFactor = +1;
                break;
            case 0:
                tree->BFactor = 0;
                child->BFactor =  0;
                break;
            case +1:
                tree->BFactor = -1;
                child->BFactor = 0;
                break;
            }
            grandChild->BFactor = 0;
            rotateToRightAndLeft(tree);
        }
    }
}
