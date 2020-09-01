#include "Book.h"

Book::Book(string fNameIn, string lNameIn, string titleIn, int yearIn) {
    firstName = fNameIn;
    lastName = lNameIn;
    title = titleIn;
    year = yearIn;
    for (int i = 0; i < 10; i++) {
        ratings[i] = 0;
    }
}

Book::Book(string fNameIn, string lNameIn, string titleIn, int yearIn, int ratingsIn[10]) {
    firstName = fNameIn;
    lastName = lNameIn;
    title = titleIn;
    year = yearIn;
    for (int i = 0; i < 10; i++) {
        ratings[i] = ratingsIn[i];
    }
}

Book::~Book() {
    cout << "destroying book" << endl;
}

double Book::average() {
    double ret = 0.0;
    for (int i = 0; i < 10; i++) {
        ret =+ ratings[i];
    }
    return (ret / 10);
}

void Book::printRatings() {
    if (ratings[0] == 0)
        cout << "(no ratings yet)" << endl;
    else {
        for (int i = 0; i < 10; i++) {
            cout << ratings[i] << ", " << endl;
        }
    }
}

void Book::printInfo() {
    cout << "Title: " << title << " by " << firstName << " " << lastName << ", written in " << year << ", average rating of " << average() << endl;
}