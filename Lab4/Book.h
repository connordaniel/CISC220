//
// Created by connor on 10/3/19.
//

#ifndef LAB4_BOOK_H
#define LAB4_BOOK_H
#include <iostream>
#include <string>
using namespace std;
class Book {
    string firstName;
    string lastName;
    int ratings[10];
    string title;
    int year;
public:
    Book(string fNameIn, string lNameIn, string titleIn, int yearIn);
    Book(string fNameIn, string lNameIn, string titleIn, int yearIn, int ratingsIn[]);
    ~Book();
    double average();
    void printRatings();
    void printInfo();

};
#endif //LAB4_BOOK_H
