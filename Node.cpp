#include "Node.h"
#include <string>
using namespace std;

Node::Node()
{ // default constructor
    // sets all ptrs to null until initialized properly
    left = nullptr;
    right = nullptr;
    parent = nullptr;
    height = 0;
    balance = 0;
}

Node::Node(int keyIn, string valueIn)
{
    left = nullptr;
    right = nullptr;
    parent = nullptr;
    // initializes the object data using passed parameters
    key = keyIn;
    value = valueIn;
    height = 0;
    balance = 0;
}

Node::~Node()
{ // default destructor
}

/*

All of these Getters and Setters are protected from segmentation faults! that is why
there are so many conditionals on every getter and setter

*/

Node *Node::getLeft()
{
    if (this != nullptr)
    {
        return left;
    }
    else
    {
        return nullptr;
    }
}
Node *Node::getRight()
{
    if (this != nullptr)
    {
        return right;
    }
    else
    {
        return nullptr;
    }
}
Node *Node::getParent()
{
    if (parent != nullptr)
    {
        return parent;
    }
    else
    {
        return nullptr;
    }
}

void Node::setHeight(int h)
{
    if (this != nullptr)
    {
        height = h;
    }
}
int Node::getHeight()
{
    if (this == nullptr)
    {
        return -1;
    }
    else
    {
        return height;
    }
}
string Node::getValue()
{
    if (this != nullptr)
    {
        return value;
    }
    else
    {
        return nullptr;
    }
}
int Node::getKey()
{
    if (this != nullptr)
    {
        return key;
    }
    else
    {
        return NULL;
    }
}
void Node::setParent(Node *ptr)
{
    if (this != nullptr)
    {
        parent = ptr; // setter function for the root var
    }
}
// other needed setters
void Node::setRight(Node *ptr)
{
    if (this != nullptr)
    {
        right = ptr;
    }
}
void Node::setLeft(Node *ptr)
{
    if (this != nullptr)
    {
        left = ptr;
    }
}

void Node::setBalance(int bal)
{
    if (this != nullptr)
    {
        balance = bal;
    }
}

int Node::getBalance()
{
    if (this != nullptr)
    {
        return balance;
    }
    else
    {
        return NULL;
    }
}