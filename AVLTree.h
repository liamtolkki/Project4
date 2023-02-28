#pragma once
#include <string>
#include <vector>

class AVLTree
{
public:
    AVLTree(){};
    ~AVLTree(){};

    bool insert(int key, std::string value){};

    int getHeight(){};

    int getSize(){};

    friend ostream &operator<<(ostream &os, const AVLTree &me){};

    bool find(int key, string &value){};

    vector<string> findRange(int lowkey, int highkey){};

private:
};