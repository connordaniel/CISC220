#include <iostream>
#include "SNode.h"
using namespace std;

SNode::SNode() {
    int in;
    cout << "Please enter a rating" << endl;
    cin >> in;
    rating = in;
    string in2;
    cout << "Please enter your comments" << endl;
    cin >> in2;
    comments = in2;
}

SNode::SNode(int r, string c) {
    rating = r;
    comments = c;
}

SNode::~SNode() {
    cout << "destroying node" << endl;
}

void SNode::printNode() {
    cout << "Ratings : " << rating << "\n Comments: \n" << comments << endl;
}