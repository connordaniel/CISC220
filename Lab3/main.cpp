#include <iostream>
#include "tictactoe.h"
#include "Box.h"
using namespace std;

class Quiz {
    int currentTest;
    int correct;
    int total;
public:
    Quiz(int in) {
        currentTest = in;
        correct = 0;
        total = 0;
    }
    void quizTime() {
        srand(time(0));
        int test = rand() % 13;
        int ans = 0;
        cout << "what is " << currentTest << " multiplied by " << test << "?" << endl;
        cin >> ans;
        if (ans == test * currentTest) {
            cout << "Correct!" << endl;
            correct++;
            total++;
        } else {
            cout << "Incorrect :(" << endl;
            total++;
        }
    }
    void stats() {
        cout << correct << " answers correct out of " << total << endl;
    }
};

class Hanning{
    int window;
    int *orig;
    int size;
    int *filter;

public:
    Hanning(int window, int orig[], int size, int filter[]);
    int weightedAverage(int in[]);
    void filterArray();
    void printGraph(bool in);
    void changeSize(int newSize);
    void printArray(bool in);
};

Hanning::Hanning(int windowIn, int origIn[], int sizeIn, int filterIn[]) {
    window = windowIn;
    orig = origIn;
    size = sizeIn;
    filter = filterIn;
}

int Hanning::weightedAverage(int in[]) {
    int radius = window / 2;
    int weight = 1;
    int ret = 0;

    for (int i = 0; i < window; i++) {
        ret += in[i] * weight;
        if (i < radius)
            weight++;
        else
            weight--;
    }
    return ret / window;
}

void Hanning::filterArray() {
    int radius = window / 2;
    for (int i = 0; i < size; i++) {
        if (i - radius >= 0 && i + radius <= size - 1)
            filter[i] = weightedAverage(&orig[i - radius]);
        else
            filter[i] = 0;
    }
}

void Hanning::printGraph(bool in) {
    if (in) {
        for (int i = window; i >= 0; i--) {
            if (i >= 0)
                cout << " ";
            cout << i << ":";
            for (int j = 0; j < size; j++) {
                if (filter[j] == i)
                    cout << "*";
                else
                    cout << " ";
            }
            cout << endl;
        }
    }
}

void Hanning::printArray(bool in) {
    if (in) {
        for (int i = 0; i < size; i++)
        cout << filter[i] << ", ";
        cout << endl;
    } else {
        for (int j = 0; j < size; j++)
            cout << orig[j] << ", ";
        cout << endl;
    }
}

void Hanning::changeSize(int newSize) {
    if (newSize % 2 == 0)
        newSize--;
    window = newSize;
}

int main() {
    Quiz run(6);
    for (int i = 0; i < 10; i++) {
        run.quizTime();
        run.stats();
    }

    int arr1[3] = {1,2,3};
    int arr2[3] = {4,5,6};

    Hanning filter(3, arr1, 3, arr2);

    filter.filterArray();

    filter.printArray(false);
    filter.printArray(true);
    filter.printGraph(false);
    filter.printGraph(true);
    filter.changeSize(5);
    filter.printArray(false);
    filter.printArray(true);
    filter.printGraph(false);
    filter.printGraph(true);

    TicTacToe game();

    //Box box1(7.1,27.8,16.7);
    //Box box2(47.2,124.7,1246.57);
   // cout << "Box1 == Box2: " << boolalpha << (box1 == box2) << endl;
return 0;
}