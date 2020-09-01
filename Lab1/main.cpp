/*
 * Connor Daniel
 *
 * 9/5/19
 * This file contains functions for lab 1.
 * They are not necessarily related in any other
 * way other than they are required for lab 1.
 */

#include <iostream>
using namespace std;

void stars();
bool isPrime(int x);
void sumTo300();
void termsTo100000();
void timesTablesTo12(int x);
void timesTablesForAll();
void collatz();
void leapYears();
void XStar(int x);
void collatz2(int small, int large);

int main() {
    cout << "Hello, World!" << endl;
    stars();
    cout << isPrime(4) << endl;
    cout << isPrime(5) << endl;
    cout << isPrime(19)<< endl;
    stars();
    sumTo300();
    stars();
    termsTo100000();
    stars();
    timesTablesTo12(12);
    stars();
    timesTablesForAll();
    stars();
    collatz();
    stars();
    leapYears();
    stars();
    XStar(5);
    XStar(6);
    XStar(9);
    stars();
    collatz2(4, 8);
    return 0;
}//main

/*
 * This function takes no input parameters and
 * returns no values and prints out a line of stars.
 */
void stars() {
    cout << "*****************" << endl;
}//stars

/*
 * This function takes in an integer and
 * uses a while loop to determine whether
 * that number is a prime number or not,
 * and returns True if it is, and False otherwise.
 */
bool isPrime(int x) {
    int count =  2;

    while (count < x) {
        if (x % count == 0)
            return true;
        count++;
    }
    return false;
}//isPrime

/*
 * This function calculates the sum 1+2+3+...+300, while also
 * displaying every 20th term
 */
void sumTo300() {
    int sum = 0;
    for (int i = 0; i <= 300; i++) {
        sum += i;
        if (sum % 20 == 0)
            cout << sum << endl;
    }
}

/*
 * This function figures out how many terms in the
 * sum 1+2+3+... it requires for the sum to exceed
 * 100,000
 */

void termsTo100000() {
    int count = 1;
    int sum = 0;
    while (sum < 100000) {
        sum += count;
        count++;
    }

    cout << count << endl;
}

/*
 * This function uses a for loop to print out the
 * multiplication tables from 1 to 12 of a given
 * integer.
 */
void timesTablesTo12(int x) {
    for (int i = 1; i <= 12; i++)
        cout << i * x << endl;
}//timesTablesTo12

/*
 *This function  loops from 1-12 and uses the function
 * in Problem 6 to print out all of the
 * multiplication tables between 1 and 12.
 */
void timesTablesForAll() {
    for (int i = 1; i <= 12; i++)
        timesTablesTo12(i);
}//timesTablesForALl

/*
 * This function uses the Collatz Conjecture
 * and counts how many times the Conjecture is
 * applied to a user-inputted number
 */
void collatz() {
    int x;
    cout << "Enter a number" << endl;
    cin >> x;
    int count = 0;
    while (x != 1) {
        count++;
        if (x % 2 == 0) {
            x /= 2;
        } else {
            x *= 3;
            x++;
        }
    }
    cout << "You looped through " << count << " times." << endl;
}//collatz

/*
 *This function prints out the next leap years for the next 400
 * years.
 */
void leapYears() {
    for (int i = 2017; i <= 2017+400; i++) {
        if (i % 4 == 0) {
            if (i % 100 == 0) {
                if ( i % 400 == 0) {
                    cout << i << endl;
                }
            } else {
                cout << i << endl;
            }
        }
    }
}//leapYears

/*
 * This function makes an x out of stars the length of
 * which is submitted by a user.
 */
void XStar(int x) {
    if (x % 2 == 0) {
        x++;
    }
    int arm = x * 2 + 1;

    for (int i = 0; i < arm; i++) {
        for (int j = 0; j < arm; j++) {
            if (i == j || j + i == arm  - 1)
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }
}//XStar

/*
 * This function takes two numbers and, for every number in between,
 * runs the Collatz Conjecture
 */
void collatz2 (int small, int large) {
    for (int i = large - 1; i >= small; i--) {
        cout << i << endl;
        while (i != 1) {
            if (i % 2 == 0) {
                i /= 2;
            } else {
                i *= 3;
                i++;
            }
        }
        cout << "Collatz Conjecture is still working." << endl;
    }
}//collatz2