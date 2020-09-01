#ifndef SNODE_HPP_
#define SNODE_HPP
#include <iostream>
using namespace std;

class SNode {
    friend class SLL;
    int rating;
    string comments;

    SNode *next;
public:
    SNode();
    SNode(int r, string c);
    ~SNode();
    void printNode();
};

#endif /* SNODE_HPP_ */