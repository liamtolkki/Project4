#include "AVLTree.h"
using namespace std;

AVLTree::AVLTree() // default constructor
{
    root = nullptr; // sets the default root pointer to null when initialized
    size = 0;       // default size = 0
    height = -1;    // height is initially -1
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
        size++;                   // increments the size whenever a node is added
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
            calculateHeight(*&current);
            return temp;
        }
        else if (key < current->getKey()) // branch left
        {

            Node *leftChild = current->getLeft();
            bool temp = insertHelper(key, value, leftChild, prev);

            current->setLeft(leftChild); // links the new node to the left branch
            calculateHeight(*&current);
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
    bool isInsert = insertHelper(key, value, root, nullptr); // passes a nullptr because the first run will have a null back ptr

    return isInsert;
}

int AVLTree::calculateHeightHelper(Node *starting)
{ // this will calculate the height after each insert and rotation
    if (starting == nullptr)
    {              // BASE CASE
        return -2; // returns -1 if there is no node
    }
    int temp = (max(calculateHeightHelper(starting->getLeft()), calculateHeightHelper(starting->getRight())) + 1);
    starting->setHeight(temp);
    return temp;
    /*
        This recursively gets the height of the current node being targeted
        This will be called everytime a rotation is done
    */
}

void AVLTree::calculateHeight(Node *start)
{
    start->setHeight(calculateHeightHelper(start));
    // gets the height of the starting node
    // needs to work it's way up the tree
    Node *current = start->getParent(); // placeholder variable
    int currentHeight = start->getHeight();
    while (current != nullptr)
    {
        // progresses up the tree until reaches parent
        currentHeight = (max(current->getLeft()->getHeight(), current->getRight()->getHeight()) + 1);
        current->setHeight(currentHeight);
        current = current->getParent();
    }
    height = currentHeight;
}

void AVLTree::checkBalance(Node *current)
{ // current is the node that is modified (rotated/added)
    while (current != nullptr)
    { // moves up the tree and recalculates the balance of every node that it lands on
        current->setBalance(current->getLeft()->getHeight() - current->getRight()->getHeight());
        if (current->getBalance() == 2 || current->getBalance() == -2) {
            //TODO rotate
        }
        current = current->getParent();
    }
}

int AVLTree::getHeight() // this returns the height (Time complexity: O(1))
{
    return height;
}

int AVLTree::getSize()
{
    return size;
}

ostream &treePrinter(ostream &os, Node *current, int height)
{
    if (current != nullptr)
    {
        treePrinter(os, current->getRight(), height);
        for (int i = 0; i < (height - current->getHeight()); i++)
        {
            // adds proper spacing based on height:
            os << string("         ");
        }
        string string1 = to_string(current->getKey());
        string string2 = string(current->getValue());
        string concat = string1 + ", " + string2 + "\n";
        os << concat;
        treePrinter(os, current->getLeft(), height);
    }
    return os;
}

ostream &operator<<(ostream &os, const AVLTree &me)
{
    return treePrinter(os, me.root, me.height);
}

bool AVLTree::find(int key, string &value)
{
}

vector<string> AVLTree::findRange(int lowkey, int highkey)
{
}