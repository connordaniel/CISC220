/*
 * Connor Daniel
 * Lab 2b
 */
#include <iostream>
#include <cmath>

using namespace std;

void problem1(int length, int &x);
void problem2(int length);
void problem3(int length, int range);
int* problem4();
void problem5(int *arr,int size);
int* problem6(int *x, int *y, int *z);
int* problem7(int x);
void problem8(int arr[], int size);
void problem9(double arr[], int size);
int* problem10(int arr[], int *size);
int problem11(int arr[], int size);
int *problem12(int *arr, int size, int view);
void problem13(int arr[], int length, int high, int low);
int **problem14(int *x, int *y);
int main() {
    int p1 = -1;
    problem1(5, p1);
    problem2(7);
    problem3(7, 50);
    int *x = problem4();
    cout << x << ", " << &x << endl;
    int arr[25];
    for (int i = 0; i < 25; i++) {
        arr[i] = rand() % 11;
    }
    int size = 25;
    problem5(arr, 25);
    problem8(arr, 25);
    double arr9[] = {1,2,3,4,5};
   // problem9(arr, 5);
    problem10(arr, &size);
    problem11(arr, 25);
    problem12(arr, 25, 3);
    int arr13[5] = {1, 2, 4, 7, 68};
    problem13(arr13, 5, 68, 1);
    int fourteenX = 0;
    int fourteenY = 0;
    int **newArray = problem14(&fourteenX, &fourteenY);
    return 0;
}

/*
 * this function takes as input parameters a length parameter (an int),
 * and an int parameter
 * that will be modified using pass by reference.
 * When the function is called the second parameter is initialized to
 * -1(before the function call).
 * The function should should generate a random array the length of
 * the length parameter, with the numbers between 1 and 50.  The
 * function should print the array, and then locate the smallest
 * value in the array, modifying the third parameter to be the smallest value.
 */
void problem1(int length, int &x) {
    int arr [length];
    for (int i = 0; i < length; i++) {
        arr[i] = rand() % 51;
        cout << arr[i] << ", " << endl;
    }
     x = arr[0];
    for (int i = 0; i < length; i++) {
        if (arr[i] < x)
            x = arr[i];
    }
    cout << x << endl;

}

/*
 * this function takes an input parameter an int and returns nothing.
 * It then generates an array of random numbers the length of the int
 * parameter.  It fills the array with random numbers between 0 and 50.
 * It then prints out the array, and then prints out the array reversed.
 */
void problem2(int length) {
    int arr[length];
    int i;
    for (i = 0; i < length; i++) {
        arr[i] = rand() % 51;
        cout << arr[i] << ", ";
    }
    cout << endl;
    int j = i - 1;
    i = 0;
    while (i < j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        j--;
        i++;
    }
    for (int x = 0; x < length; x++) {
        cout << arr[x] << ", ";
    }
    cout << endl;
}

/*
 * This function takes as an input parameter an integer that will
 * represent the length of the array and a second integer that represents
 * the range of numbers the random number should generate (in other words,
 * if the number is 50, the random number generator should generate numbers
 * between 0 and 49 including 49.
 * then sorts the list by traversing the list, locating the smallest number,
 * and printing out that smallest number, then replacing that
 * number in the array with the second parameter +1 (so in our above example,
 * it would be 51. )  Continue to do this until every number in the original
 * array is printed out in order.
 */
void problem3(int length, int range) {
    srand(time(0));
    int arr [length];
    for (int i = 0; i < length; i++) {
        arr[i] = rand() % range;
    }
    int small = arr[0];
    for (int i = 0; i < length; i++) {
        for (int i = 0; i < length; i++) {
            if  (small > arr[i]) {
                cout << arr[i] << endl;
                arr[i] = range + 1;
            }
        }
    }
}

/*
 * this function creates a new variable on the stack.  Give the variable a value of 3.
 * Print out the value and the address of the variable within the function.
 * Return the address of this variable,and make sure that main has a pointer
 * set to the returned variable (int *x = func();Print out the address of
 * the variable and the value in the variable in main.  Did this work?
 * Did it compile?  Include a comment on those 2 questions.
 */
int* problem4() {
    int ret = 3;
    cout << ret << ", " << &ret << endl;
    return &ret;
}

/*
 * This function takes an array of integers as an input parameter (the address of the first
 * value of the array)and an integer for the sizeof the array.  It returns nothing.
 * It prints out the array as a single line, with commas between each number,
 * and when the array is finished being printed, it prints an endl; so that we
 * flush the buffer and move to a new line.
 */
void problem5(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << ", ";
    }
    cout << endl;
}

/*
 * This function takes as input parameters (using call by pointer) 3 integers.  It generates a random
 * number between 25 and 50 (not including 50).  It then creates an array on the memory heap of that length.
 * It generates a random high number between 5 and 10 and a random low number between -5 and -10
 * and fills in the array iteratively with random numbers between the high and the low numbers*,
 * and it returns that array. The input parameters should be modified so that it holds the length of the array,
 * the high value, and the low value. In main, call the function 5to print out the array
 */
int *problem6(int *size, int *high, int *low) {
    srand(time(0));
    int *arr = new int [*size];
    for (int i = 0; i < *size; i++) {
        arr[i] = rand() % (*high - *low);
    }
    return arr;

}

/*
 * This function is almost exactly the same as the function above, only it takes an input parameter an integer
 * (pass in a number between 25 and 50).  Inside the function create an array on the stack instead of the heap.
 * Fill it with random numbers as above.  Return the address of the first value of the array,
 * and then in the main use function 1 to print it out.  This should NOT work.
 */
/*
int* problem7(int in) {
    int arr [in];
    for (int i = 0; i < in; i++) {
        arr[i] = rand() % (10- -10);
    }
    return &arr[0];
}
*/ //This does not work because the array does not exist outside the scope of the problem.

/*
 * This function prints out the address of every address in the inputted array
 */
void problem8(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << &arr[i] << ", ";
    }
    cout << endl;
}//problem8

/*
 * This function prints out the addresses of an array of doubles.
 */
void problem9(double arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << &arr[i] << ", ";
    }
    cout << endl;
}//problem9

/*
 * This function traverses an array of ints and removes all double numbers.
 */
int* problem10(int arr[], int *size) {
    int *ret = new int[*size];
    int count = 0;
    for (int i = 0; i < *size; i++) {
        if (arr[i] == arr[i + 1]) {
            ret[count] = arr[i];
            count++;
            i++;
            while(arr[i] == arr[i + 1])
                i++;

        } else {
            ret[count] = arr[i];
            count++;
        }
    }
    for (int i = count; i < *size; i++)
        delete(&ret[i]);
    *size = count;
    return ret;
}//problem 10

/*
 * This function creates a Hanning Window
 */
int problem11(int arr[], int size) {
    double avg = 0;
    int weight = 0;
    int wSize = 0;
    for (int i = 0; i < wSize; i++) {
        if (i < (wSize - 1) / 2)
            weight = i + 1;
        else
            weight = wSize - 1;
        avg += arr[i] * weight;
        wSize =+ weight;
    }
    avg /= wSize;
    return (int) round(avg);
}

/*
 * This function filters the array
 */
int *problem12(int *arr, int size, int view) {
    int *filter = new int[size];
    int math = (view - 1) / 2;
    for (int i = math; i < size - math; i++)
        filter[i] = problem11(&arr[i - math], view);
    for (int i = 0; i < math; i++) {
        filter[i] = 0;
        filter[size - i - 1] = 0;
    }
    cout << endl;
    return filter;
}

/*
 * This function prints out the graph
 */
void problem13(int arr[], int length, int high, int low) {
    for (int i = high; i >= low; i--) {
        if (i >= 0)
            cout << " ";
        cout << i << ":";
        for (int j = 0; j < length; j++) {
            if (arr[j] == i)
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }
}

/*
 * This function creates a two dimensional
 * array and returns the address of it
 */
int **problem14(int *x, int *y) {
    srand(time(0));
    *x = rand() % 10 + 5;
    *y = rand() % 8 + 4;
    int **arr = new int *[*x];
    for (int i = 0; i < *x; i++)
        arr[i] = new int[*y];
    for (int i = 0; i < *x; i++) {
        for (int j = 0; j < *y; j++)
            arr[i][j] = 0;
    }
    for (int i = 0; i < 5; i++)
        arr[rand() % *x][rand() % *y] = 1;
    return arr;
}