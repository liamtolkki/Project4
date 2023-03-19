#pragma once
#include <string>
#include <vector>
#include <stack>
#include "Node.h"
using namespace std;
class AVLTree
{
public:
    AVLTree();
    ~AVLTree();

    bool insert(int key, std::string value);

    int getHeight();

    void calculateHeight(stack<Node*> treeStack);

    stack<Node *> getTreeStack(Node * nodeIn);

    void checkBalance(stack <Node *> &TreeStack);

    void balancer(Node *current);

    int getSize();

    friend ostream &treePrinter(ostream &os, Node *current, int height);

    friend ostream &operator<<(ostream &os, const AVLTree &me);

    bool find(int key, string &value);

    vector<string> findRange(int lowkey, int highkey);

private:
    Node *root;
    int size;   // holds the size of the AVL tree
    int height; // height of the tree
};