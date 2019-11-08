#include "BinHeap.hpp"
#include <string>
#include <iostream>
#include <stdlib.h>

using namespace std;
BinHeap::BinHeap(string arr[], int len) {
    heaplen = 0;
    arrlen = len;
    heap = new string[arrlen];
    for (int i = 0; i < len; i++) {
        insertHeap(arr[i]);
    }
    printHeap();
}
BinHeap::~BinHeap() {
    delete [] heap;
}
void BinHeap::printHeap() {
    cout << endl;
    for (int i = 0; i < arrlen; i++) {
        cout << i << ", ";
    }
    cout << endl;
    for (int i = 0; i < heaplen; i++) {
        cout << heap[i] << ", ";
    }
    cout << endl;
}

int BinHeap::findMax(int x, int y) {
    if ((x < heaplen)  && (y < heaplen)) {
        if (heap[x] > heap[y])
            return(x);
        else
        {
            return(y);
        }
    } else if (x < heaplen) {
        return x;
    }
    else return -1;
}

void BinHeap::bubbleDown(int i) {
    int curr = i;
    int temp = 0;
    while (((heap[2 * curr + 1].compare(heap[curr]) < 0) && (heap[2 * curr + 2].compare(heap[curr]) < 0 ) || (heap[curr + 1].compare(NULL) == 0) {
        if (heap[curr] < findMax(2 * curr + 1], 2 * curr + 2)) {
        int max = findMax(2 * curr + 1,2 * curr + 2);
        temp = heap[curr];
        heap[curr] =  max;
        curr = indexOf(max);
        heap[indexOf(max)] = temp;
        }
    }
}

void BinHeap::bubbleUp(int i) {
    int curr = i;
    int temp = 0;
    while (curr != 0 || heap[(curr - 1) / 2] > heap[curr]) {
        temp = heap[curr];
        heap[curr] = heap[]
        curr = curr - 1 / 2;

    }
}

void BinHeap::insertHeap(string s) {
    int x;
    for (int i = 0; i < heaplen; i++) {
        if (heap[i].compare(NULL) == 0) {
            heap[i] = s;
            x = i;
        }
    }
    bubbleUp(x);
    heaplen++;
}

string BinHeap::deleteHeap() {
    string ret;
    ret = heap[0];
    for (int i = 0; i < heaplen;i++) {
        if (heap[i].compare(NULL) == 0) {
            heap[0] = heap[i - 1];
            heap[i - 1] = NULL;
            break;
        }
    }
    bubbleDown(0);
    heaplen--;
    return ret;
}
/***************************************************************************/
/*Part 2*/
string BinHeap::deleteHeap2() {
    string ret;
    string save = heap[0];
    ret = heap[0];
    for (int i = 0; i < heaplen;i++) {
        if (heap[i].compare(NULL) == 0) {
            heap[0] = heap[i - 1];
            heap[i - 1] = NULL;
            break;
        }
    }
    bubbleDown(0);
    heaplen--;
    heap[heaplen + 1] = save;
    return ret;
}
void BinHeap::deleteAll() {
    int save = heaplen;
    for (int i = 0; i < heaplen; i++) {
        deleteHeap2();
    }
    heaplen = save;
}