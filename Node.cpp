#include "Node.h"
#include <string>
using namespace std;

Node::Node()
{ // default constructor
    // sets all ptrs to null until initialized properly
    left = nullptr;
    right = nullptr;
    parent = nullptr;
}

Node::Node(int keyIn, string valueIn)
{
    left = nullptr;
    right = nullptr;
    parent = nullptr;
    // initializes the object data using passed parameters
    key = keyIn;
    value = valueIn;
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
string Node::getValue()
{
    return value;
}
int Node::getKey()
{
    return key;
}
Node *Node::setParent(Node *ptr)
{
    parent = ptr; // setter function for the root var
}
// other needed setters
Node *Node::setRight(Node *ptr)
{
    right = ptr;
}
Node *Node::setLeft(Node *ptr)
{
    left = ptr;
}