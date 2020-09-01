#include "SLL.h"
#include <iostream>
using namespace std;

SLL::SLL() {
    first = NULL;
    last = NULL;
    size = 0;
}

SLL::~SLL() {
    cout << "destroying node" << endl;
}

void SLL::printSLL() {
    SNode *tmp = first;
    int count = 1;
    while (tmp != NULL) {
        tmp->printNode();
        tmp = tmp->next;
    }
    cout << endl;
}

void SLL::insertInOrder(int r, string c) {
    SNode *tmp = first;
    if (first == NULL)
        addFirst(r, c);
    if (r < first->rating)
        addAtFront(r, c);
    if (r > last->rating)
        push(r, c);
    Snode *insert = new SNode(r, c);
    while (tmp->rating < r)
        tmp = tmp->next;
    tmp->next = insert;
    size++;
}

void SLL::push(int r, string c) {
    SNode *tmp = last;
    SNode *p = new SNode(r, c);
    tmp->next = p;
    last = p;
    size++;
}

void SLL::addAtFront(int r, string c) {
    SNode *in = new SNode(r, c);
    in->next = first;
    first = in;
    size++;
}

void SLL::addFirst(int r, string c) {
    first = new SNode(r, c);
    last = first;
    size++;
}

int SLL::pop() {
    SNode *tmp = first;
    for (int i = 0; i < size - 1; i++) {
        tmp = tmp->next;
    }
    int ret = tmp->rating;
    last = tmp;
    delete tmp;
    last->next = NULL;
    size--;
    return ret;
}

double SLL::getAve() {
    double ret = 0.0;
    SNode *tmp = first;
    for (int i = 0; i < size; i++) {
        ret += tmp->rating;
        tmp = tmp->next;    int ret = tmp->rating;

    }
    return (ret / size);
}