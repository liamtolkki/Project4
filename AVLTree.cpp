#include "AVLTree.h"
using namespace std;

AVLTree::AVLTree() // default constructor
{
    root = nullptr; // sets the default root pointer to null when initialized
}

AVLTree::~AVLTree() // default destructor
{
}

bool AVLTree::insert(int key, string value)
{
    return insertHelper(key, value, root, root->getRoot());
}
bool insertHelper(int key, string value, Node *current, Node *prev) // recursive
{
    if (current == nullptr)
    { // if there is no node where there should be one, it creates one
        current = new Node(key, value);
        current->setRoot(prev); // sets prev to be the parent node, not the tree root
        return true;
    }
    else
    {
        if (key > current->getKey()) // branch right
        {
            current = current->getRight(); // updates current with right node if larger
            return insertHelper(key, value, current, prev);
        }
        else if (key < current->getKey()) // branch left
        {
            current = current->getLeft();
            return insertHelper(key, value, current, prev);
        }
        else // if duplicate value, return false
        {
            return false;
        }
    }
}

int AVLTree::getHeight()
{
}

int AVLTree::getSize()
{
}

ostream &operator<<(ostream &os, const AVLTree &me)
{
}

bool AVLTree::find(int key, string &value)
{
}

vector<string> AVLTree::findRange(int lowkey, int highkey)
{
}