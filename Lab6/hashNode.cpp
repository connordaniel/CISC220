#include "hashNode.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

hashNode::hashNode(string s) {
    keyword = s;
    valuesSize = 100;
    currSize = 0;
    values = new string [valuesSize];
}

hashNode::hashNode(string s, string v) {
    keyword = s;
    valuesSize = 100;
    currSize = 1;
    values = new string [valuesSize];
    values[0] = v;
}

void hashNode::addValue(string v) {
    values[currSize] = v;
    currSize++;
    if (currSize >= valuesSize)
        dblArray();
}

void hashNode::dblArray() {
    string newArr[valuesSize * 2];
    for (int i = 0; i < valuesSize; i++) {
        newArr[i] = values[i];
    }
    values = newArr;
}

string hashNode::getRandValue() {
    if (currSize == 0)
        return "";
    else 
        return values[rand() % currSize + 1];
}