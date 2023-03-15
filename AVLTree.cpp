#include "AVLTree.h"
using namespace std;

AVLTree::AVLTree() // default constructor
{
    root = nullptr; //sets the default root pointer to null when initialized
}

AVLTree::~AVLTree() // default destructor
{
}

bool AVLTree::insert(int key, string value)
{
    return insertHelper(key, value);
}
bool insertHelper(int key, string value) // recursive
{
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