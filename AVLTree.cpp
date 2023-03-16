#include "AVLTree.h"
using namespace std;

AVLTree::AVLTree() // default constructor
{
    root = nullptr; // sets the default root pointer to null when initialized
    size = 0;       // default size = 0
}

AVLTree::~AVLTree() // default destructor
{
}
bool AVLTree::insertHelper(int key, string value, Node *&current, Node *prev) // recursive
{
    Node *tempNode = current; // holds place for linking
    if (current == nullptr)
    { // if there is no node where there should be one, it creates one
        current = new Node(key, value);
        size++; //increments the size whenever a node is added
        current->setParent(prev); // sets prev to be the parent node, not the tree root
        if (root == nullptr)
        {
            root = current; // sets the root pointer if it is null (should only happen on first pass)
        }
        return true;
    }
    else
    {
        prev = current;              // updates the prev pointer
        if (key > current->getKey()) // branch right
        {
            Node *rightChild = current->getRight();
            bool temp = insertHelper(key, value, rightChild, prev);
            // runs recursive function but allows for me to modify
            // something before returning

            current->setRight(rightChild); // links the new node to the right branch
            return temp;
        }
        else if (key < current->getKey()) // branch left
        {

            Node *leftChild = current->getLeft();
            bool temp = insertHelper(key, value, leftChild, prev);

            current->setRight(leftChild); // links the new node to the left branch
            return temp;
        }
        else // if duplicate value, return false
        {
            return false;
        }
    }
}

bool AVLTree::insert(int key, string value)
{
    return insertHelper(key, value, root, nullptr); // passes a nullptr because the first run will have a null back ptr
}

int AVLTree::getHeight()
{
}

int AVLTree::getSize()
{
    return size;
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