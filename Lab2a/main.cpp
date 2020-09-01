#include <iostream>
using namespace std;
void swap (int *x, int *y);
void swap2 (int &x, int &y);
void problem1();
void problem2(int &x);
int problem3();
void problem4(int &x);
void problem5(int &x);
void problem6(int *x, int *y);
void problem7(char &x, char &y);
bool problem8a(int &first, int &second);
void problem8b();
int main() {
    int x = 3;
    cout << x << endl;
    cout << &x << endl;

    int *y = &x;
    cout << *y << endl;
    cout << y << endl;
    cout << &x << endl;
    cout << &y << endl;
    x = 5;
    cout << *y << endl;

    *y = 45;
    cout << x << endl;
    int a = 2;
    int b = 4;
    cout << a << b << endl;
    swap(a,b);
    cout << a << b << endl;
    swap2(a, b);
    cout << a << b << endl;
    //END OF TRY ON COMPUTER
    problem1();
    int problemTwo = 2;
    cout << problemTwo << &problemTwo << endl;
    problem2(problemTwo);
    int problemThree = problem3();
    cout << problemThree << " " << &problemThree << endl;
    int problemFour = 2;
    cout << problemFour << ", " << &problemFour << endl;
    problem4(problemFour);
    cout <<problemFour << ", " << &problemFour << endl;
    int problemFive = 4;
    cout << problemFive << ", " << &problemFive << endl;
    problem5(problemFive);
    int problemSix1 = 10;
    int problemSix2 = 20;
    problem6(&problemSix1, &problemSix2);
    cout << problemSix1 << "," << problemSix2 << endl;
    char problemSeven1 = 'h';
    char problemSeven2 = 'i';
    cout << problemSeven1 << problemSeven2 << endl;
    problem7(problemSeven1, problemSeven2);
    cout << problemSeven1 << problemSeven2 << endl;
    int eightA = 4;
    int eightB = 6;
    problem8a(eightA, eightB);
    cout << eightA << " " << eightB << endl;
    problem8b();
    return 0;
}

void swap(int *x, int *y) {
    int *tmp = x;
    x = y;
    y = tmp;
}
void swap2(int &x, int &y) {
    int tmp = x;
    x = y;
    y = tmp;

}
/*
 * This function has no parameters or return values.
 * It prints out a variable's value and memory address.
 */
void problem1() {
    int x = 4598;
    cout << x << &x << endl;
}//problem1

/*
 * This function adds 4 to an integer created in main,
 * via call by reference.
 */
void problem2 (int &x) {
    x += 4;
    cout << x << " " << &x;
}//problem2

/*
 * this function creates an integer and sets it to be a random
 * number between 0 and 50.
 */
int problem3() {
    int ret = rand() % 50;
    cout << ret << " " << &ret << endl;
    return ret;
}//problem3

/*
 * this function takes the value of the integer parameter's
 * address and cubes the value.
 */
void problem4(int &x) {
    x = x * x * x;
    cout << x << ", " << &x << endl;
}//problem4

/*
 * this function creates a random number from 1 to 10
 * and adds it to an inputted integer via call by
 * reference.
 */
void problem5(int &x) {
    int add = rand() % 11;
    x =+ add;
    cout << add << ", " << x << ", " << &x << endl;
}//problem5

/*
 * this function changes two inputted integers by call by pointer
 */
void problem6(int *x, int *y) {
    int *a = x;
    *a = 32;
    *a = *y;
    *a = 42;
}//problem6

/*
 * this function uses call by value, reference, and pointer
 * to change a word
 */
void problem7(char &x, char &y) {
    x = 'e';
    y = 'h';
}//problem7

/*
 * this problem takes in two integers, and if the first is larger
 * than the second, swaps the two integers.
 */
bool problem8a(int &first, int &second) {
    if (first > second) {
        int tmp = first;
        first = second;
        second = tmp;
        return true;
    } else
        return false;
}//problem8a

/*
 * this function generates 20 sets of two random numbers, and,
 * if the first one is larger, passes those values to 8a.
 */
void problem8b() {
    for (int i = 1; i <= 20; i++) {
        int x = rand() % 26;
        int y = rand() % 26;
        cout << x << ", " << y << endl;
        if (problem8a(x, y)) {
            cout << x << ", " << y << endl;
        }
    }
}//problem8b