#include <iostream>
#include <string>
#include "Book.h"
#include "Book.cpp"
using namespace std;
 int main() {
     Book *b1 = new Book("donkey", "boy", "i'm a donkey", 3194);
     Book *b2 = new Book("name2", "lastname2", "title2", 32456);
     Book *b3 = new Book("name3", "lastname3", "title3" , 4567);
     Book *b4 = new Book("name4", "lastname4","titel4", 134);
     Book *b5 = new Book("name5", "lastname5", "title5", 3246);
    Book *newBook = new Book("bruce", "wayne", "i'm not batman", 1939);
     Book books[5] = {*b1, *b2, *b3, *b4, *b5};

     b1->printInfo();
     Book books2[2] = {*b1, *newBook};
     for (int i = 0; i < 2; i++) {
         books2[i].printInfo();
     }

 }