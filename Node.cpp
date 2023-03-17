#include "Node.h"
#include <string>
using namespace std;

Node::Node()
{ // default constructor
    // sets all ptrs to null until initialized properly
    left = nullptr;
    right = nullptr;
    parent = nullptr;
    height = -1;
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
    height = -1;
    balance = 0;
}

Node::~Node()
{ // default destructor
}

Node *Node::getLeft()
{
    return left;
}
Node *Node::getRight()
{
    return right;
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
    height = h;
}
int Node::getHeight()
{
    if (this == nullptr)
    {
        return -2;
    }
    else
    {
        return height;
    }
}
string Node::getValue()
{
    return value;
}
int Node::getKey()
{
    return key;
}
void Node::setParent(Node *ptr)
{
    parent = ptr; // setter function for the root var
}
// other needed setters
void Node::setRight(Node *ptr)
{
    right = ptr;
}
void Node::setLeft(Node *ptr)
{
    left = ptr;
}

void Node::setBalance(int bal) {
    balance = bal;
}

int Node::getBalance() {
    return balance;
}