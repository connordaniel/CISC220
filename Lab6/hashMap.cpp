#include "hashMap.hpp"
#include "hashNode.hpp"
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

 hashMap::hashMap(bool hash1, bool coll1) {
     map = new hashNode*[mapSize];
     for (int i = 0; i < mapSize; i++)
        map[i] = NULL;
    hash1 = true;
    coll1 = true;
 }

void hashMap::addKeyValue(string k, string v) {
    if (mapSize * .7 < numKeys)
        reHash();
    int hash = 0;
    if (h1)
        hash = calcHash(k);
    else 
        hash = calcHash2(k);

    if (map[hash] == NULL) {
        hashNode *n = new hashNode(k);
        n->addValue(v);
        map[hash] = n;
        numKeys++;
    } else {   
        map[hash]->addValue(v);
        if (c1)
            hash = collHash1(hash);
        else
            hash = collHash2(hash); 
        hashNode *n = new hashNode(k);
        map[hash] = n;
    }
}

 int hashMap::calcHash(string k) {
    int num = 0;
    char arr[k.length() + 1];
    strcpy(arr,k.c_str());  
    for (int i = 0; i < k.length() + 1; i++) {
        num += (int) (arr[i]);
        //converts each character of the string to its ASCII 
        //equivalent, then adds them together
    }
    return num % mapSize;
 }

 int hashMap::calcHash2(string k) {
    int max = mapSize;
    char arr[k.length() + 1];
    strcpy(arr,k.c_str());  
    for (int i = 0; i < k.length() + 1; i++) {
        max -= (int) (arr[i]);
        //converts each character of the string to its ASCII 
        //equivalent, then subtracts each value from 500
    }
    return max % mapSize;
 }

int hashMap::collHash1(int h) {
    for (int i = h; i < mapSize; i++) {
        if(map[i] == NULL)
            return i;
    }
    for (int i = 0; i < h; i++) {
        if (map[i] == NULL)
            return i;
    }
}

int hashMap::collHash2(int h) {
    for (int i = h; i < mapSize; i++) {
        if (map[(i * i) % mapSize] == NULL)
            return i;
    }
}
void hashMap::getClosestPrime() {
    for (int i = mapSize; i < i * 2 - 2; i++) {
        if (isPrime(i))
            mapSize = i;
    }
}

bool isPrime(int n) { //helper for getClosestPrime 
    if (n <= 1) 
        return false;   
    for (int i = 2; i < n; i++) 
        if (n % i == 0) 
            return false; 
    return true; 
} 


void hashMap::reHash() {
    int x;
    int oldMapSize = mapSize;
    getClosestPrime();
    hashNode **old = map;
    map = new hashNode*[mapSize];
    for (int i = 0; i < mapSize; i++) {
        map[i] = NULL;
    }

    for (int j = 0; j < oldMapSize; j++) {
        if (old[j] != NULL) {
            x = getIndex(old[j]->keyword);
            map[x] = old[j];
        }
    }
}

int hashMap::getIndex(string k) {
    int x = calcHash(k);
    if (map[x] == NULL)
        return x;
    else {
        while (map[x] != NULL) {
            if (!((mapSize <= x) || (map[x]->keyword != k))) {
                return x;
            }
        }
    }
}

int hashMap::findKey(string k) {
    int index;
    int count;
    if (h1)
        index = calcHash(k);
    else
        index = calcHash2(k);
    if (map[index]->keyword == k)
        return index;
    else {
        while ((map[index]->keyword != k) && (count <= numKeys)) {
            if (map[index] == NULL)
                return -1;
            count++;
            index = calcHash(map[index + 1]->keyword);
        }
    }
}
void hashMap::printMap() {
    for (int i = 0; i < mapSize; i++) {
        cout << i << ": ";
        cout << map[i]->keyword << ", ";
    }
    cout << endl;
}