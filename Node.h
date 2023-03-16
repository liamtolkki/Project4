#pragma once
#include <string>
using namespace std;

class Node
{
private:
    Node *right;  // points to the right child of the current node
    Node *left;   // points to the left child
    Node *parent; // points to the parent of the current node
    int key;      // holds the numerical data
    string value; // holds the string data
    int height;   // holds current node height

public:
    Node();
    Node(int key, string value);
    ~Node();
    Node *getRight(); // getters for related nodes
    Node *getLeft();
    Node *getParent();
    void setHeight(int h);
    int getHeight();
    string getValue();
    int getKey();
    void setParent(Node *ptr);
    void setRight(Node *ptr);
    void setLeft(Node *ptr);
    
};