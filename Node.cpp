#include "Node.h"
#include <string>
using namespace std;

Node::Node(){ //default constructor
}

Node::Node(int key, string value) {

}

Node::~Node(){ //default destructor

}

Node* Node::getLeft(){
    return left;
}
Node* Node::getRight(){
    return right;
}
Node* Node::getRoot(){
    return root;
}