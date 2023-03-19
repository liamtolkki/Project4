#include "AVLTree.h"
#include <stack>
#include "Node.h"
using namespace std;

AVLTree::AVLTree() // default constructor
{
    root = nullptr; // sets the default root pointer to null when initialized
    target = nullptr;
    size = 0;    // default size = 0
    height = -1; // height is initially -1
}

AVLTree::~AVLTree() // default destructor
{
}

// My majestic failure of a recursive insert function lies here!!!!!!

// bool AVLTree::insertHelper(int key, string value, Node *&current, Node *prev) // recursive
//{
//     Node *tempNode = current; // holds place for linking
//     if (current == nullptr)
//     { // if there is no node where there should be one, it creates one
//         current = new Node(key, value);
//         size++;                   // increments the size whenever a node is added
//         current->setParent(prev); // sets prev to be the parent node, not the tree root
//         if (root == nullptr)
//         {
//             root = current; // sets the root pointer if it is null (should only happen on first pass)
//         }
//         return true;
//     }
//
//     else
//     {
//         prev = current;              // updates the prev pointer
//         if (key > current->getKey()) // branch right
//         {
//             Node *rightChild = current->getRight();
//             bool temp = insertHelper(key, value, rightChild, prev);
//             // runs recursive function but allows for me to modify
//             // something before returning
//
//             current->setRight(rightChild); // links the new node to the right branch
//             calculateHeight(*&current);
//             checkBalance(*&current);
//             return temp;
//         }
//         else if (key < current->getKey()) // branch left
//         {
//
//             Node *leftChild = current->getLeft();
//             bool temp = insertHelper(key, value, leftChild, prev);
//
//             current->setLeft(leftChild); // links the new node to the left branch
//             calculateHeight(*&current);
//             checkBalance(*&current);
//             return temp;
//         }
//         else // if duplicate value, return false
//         {
//             return false;
//         }
//     }
// }

bool AVLTree::insert(int key, string value)
{
    /*
    I tried to implement this recursively, and I am not lying when I say this:
    I SPENT 40 HOURS TRYING! I kept getting SEG-Faults due to my rotations throwing off
    the recursive stack frames! every other recursive function worked for me
    but i finally gave up on trying to make this one recursive! (I didn't want to cheat)
    I will leave the original attempted code, but it will be commented out above this! :)

    This was the OG function call that would be here:
    // bool isInsert = insertHelper(key, value, root, nullptr); // passes a nullptr because the first run will have a null back ptr

    */

    // I will use a stack to track the tree progression:
    stack<Node *> treeStack;
    bool isInsert;
    Node *current;
    // get root (if present)
    if (root == nullptr)
    {
        root = new Node(key, value);
        size++;
        isInsert = true;
        current = root;
        treeStack.push(current);
    }
    else
    {
        current = root;
        // Find spot to insert:
        while (current != nullptr)
        { // go down the tree...

            treeStack.push(current); // holds the path to the node being inserted
            if (key > current->getKey())
            {
                current = current->getRight();
                if (current != nullptr)
                {
                    treeStack.push(current);
                }
            }
            else if (key < current->getKey())
            {
                current = current->getLeft();
                if (current != nullptr)
                {
                    treeStack.push(current);
                }
            }
            else
            {
                // dupe val
                return false;
            }
        }
        size++; // increments the size of the array
        // compare last node to key
        Node *parent = treeStack.top();
        isInsert = true;
        current = new Node(key, value);
        if (key > parent->getKey())
        {
            parent->setRight(current);
        }
        else
        {
            parent->setLeft(current);
        }
        current->setParent(parent);
    }
    calculateHeight(root);
    checkBalance(treeStack); // checks balance
    if (target != nullptr)
    {
        treeStack = getTreeStack(target);
        calculateHeight(root);
        checkBalance(treeStack);
    }
    target = nullptr;
    height = root->getHeight();
    return isInsert;
}

stack<Node *> AVLTree::getTreeStack(Node *nodeIn) // this assumes that the node will always be found
{                                                 // this will find an element and create a tree stack (path to node)
    stack<Node *> treeStack;
    Node *current = root; // always start with root
    treeStack.push(current);
    while (nodeIn->getKey() != current->getKey())
    { // loop until found
        if (nodeIn->getKey() > current->getKey())
        {
            current = current->getRight();
        }
        if (nodeIn->getKey() < current->getKey())
        {
            current = current->getLeft();
        }
        treeStack.push(current);
    }
    return treeStack;
}
void AVLTree::calculateHeight(Node *current)
{
    root->setHeight(calculateHeightHelp(root));
}

int AVLTree::calculateHeightHelp(Node *current)
{
    if (current == nullptr)
    {
        return -1;
    }
    int curHeight = (max(calculateHeightHelp(current->getRight()), calculateHeightHelp(current->getLeft())) + 1);
    current->setHeight(curHeight);
    return curHeight;
}

void AVLTree::checkBalance(stack<Node *> &treeStack)
{                  // current is the node that is modified (rotated/added)
    Node *problem; // will point to the problem node if found

    while (!treeStack.empty())
    { // moves up the tree and recalculates the balance of every node that it lands on
        Node *current = treeStack.top();
        current->setBalance(current->getLeft()->getHeight() - current->getRight()->getHeight());
        if (target != nullptr)
        {
            if (target->getBalance() < 2 && target->getBalance() > -2)
            {
                target = nullptr; // clears out the target if it is back in balance
            }
        }
        if (current->getBalance() >= 2 || current->getBalance() <= -2)
        {
            target = current;
            problem = current;
            balancer(problem);
            calculateHeight(root);
        }
        treeStack.pop();
    }
}

void AVLTree::singleRight(Node *problem)
{
    // Next 5 lines hold the necessary rotation node data
    Node *hook = problem->getLeft(); // grabs hook node
    Node *problemParent = problem->getParent();
    Node *subtreeA = hook->getLeft();     // holds the hook's left child
    Node *subtreeB = hook->getRight();    // holds the hook's right child
    Node *subtreeC = problem->getRight(); // the right child of the problem node
    // now for the rotation!
    hook->setParent(problemParent);
    if (problemParent == nullptr)
    {
        root = hook; // sets the new root if needed
    }
    // rotate hook and problem node
    hook->setRight(problem);
    // plug back in subtrees (if any)
    hook->setLeft(subtreeA);
    problem->setLeft(subtreeB);
    problem->setRight(subtreeC);
    // reroute the root's child to hook:
    if (problemParent->getKey() > hook->getKey())
    {
        problemParent->setLeft(hook);
    }
    else
    {
        problemParent->setRight(hook);
    }
    // DONE!
}

void AVLTree::singleLeft(Node *problem)
{
    Node *hook = problem->getRight(); // grabs hook node
    Node *problemParent = problem->getParent();
    Node *subtreeA = problem->getLeft();
    Node *subtreeB = hook->getLeft();
    Node *subtreeC = hook->getRight();
    hook->setParent(problemParent);
    if (problemParent == nullptr)
    {
        root = hook; // sets the new root if needed
    }
    // swap hook and problem nodes:
    hook->setLeft(problem);
    problem->setParent(hook);
    // plug back in subtrees (if any)
    problem->setLeft(subtreeA);
    problem->setRight(subtreeB);
    hook->setRight(subtreeC);
    // reroute the root's child to hook:
    if (problemParent->getKey() > hook->getKey())
    {
        problemParent->setLeft(hook);
    }
    else
    {
        problemParent->setRight(hook);
    }
    // DONE!
}

void AVLTree::rightLeft(Node *problem)
{
}

void AVLTree::leftRight(Node *problem)
{
}

void AVLTree::balancer(Node *problem)
{ // this applies the node balancing operations

    if ((problem->getBalance() == 2) && ((((problem->getLeft()->getBalance()) == 1) || (problem->getLeft()->getBalance() == 0))))
    {
        // single right rotation
        singleRight(problem);
    }

    if ((problem->getBalance() == -2) && ((((problem->getLeft()->getBalance()) == -1) || (problem->getLeft()->getBalance() == 0))))
    {
        // single left rotation
        singleLeft(problem);
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