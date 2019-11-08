#ifndef BINHEAP_HPP_
#define BINHEAP_HPP_
#include <string>
using namespace std;

class BinHeap {
    public:
        int heaplen;
        int arrlen;
        string *heap;
        
        BinHeap(string arr[], int len);
        ~BinHeap();
        void printHeap();
        int findMax(int x, int y);
        void bubbleDown(int i);
        void bubbleUp(int i);
        void insertHeap(string s);
        string deleteHeap();
        string deleteHeap2();
        void deleteAll();
};

#endif /* BINHEAP_HPP_ */
