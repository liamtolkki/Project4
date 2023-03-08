#pragma once
#include <string>

class Node
{
private:
    Node::Node *right; // points to the right child of the current node
    Node::Node *left;  // points to the left child
    Node::Node *root;     // points to the parent of the current node
    int key; //holds the numerical data
    string value; //holds the string data

public:
    Node(){};
    ~Node(){};
    Node::Node* getRight(){}; //getters for related nodes
    Node::Node* getLeft(){};
    Node::Node* getRoot(){};
};