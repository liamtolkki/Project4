#include "Node.h"
#include <string>
using namespace std;

Node::Node()
{ // default constructor
    // sets all ptrs to null until initialized properly
    left = nullptr;
    right = nullptr;
    root = nullptr;
}

Node::Node(int keyIn, string valueIn)
{
    left = nullptr;
    right = nullptr;
    root = nullptr;
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
Node *Node::getRoot()
{
    if (root != nullptr)
    {
        return root;
    } else {
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
Node *Node::setRoot(Node *ptr)
{
    root = ptr; // setter function for the root var
}