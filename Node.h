#pragma once
#include <string>

class Node
{
private:
    Node::Node *rightChild; // points to the right child of the current node
    Node::Node *leftChild;  // points to the left child
    Node::Node *parent;     // points to the parent of the current node
    int key; //holds the numerical data
    string value; //holds the string data

public:
    Node(){};
    ~Node(){};
    Node::Node* getRightChild(){}; //getters for related nodes
    Node::Node* getLeftChild(){};
    Node::Node* getParent(){};
};