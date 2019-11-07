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
    int temp = 0;
    while ((heap[i + 1]))
        if (heap[i] < findMax(heap[i + 1], heap[i + 2])) {
        int max = findMax(heap[i + 1], heap[i + 2]);
        temp = heap[i];
        heap[i] =  max;
        max = temp;
        }
}