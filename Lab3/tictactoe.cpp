#include "tictactoe.h"
#include <iostream>
using namespace std;

TicTacToe::TicTacToe(){
    board = new char *[3];
    for (int i = 0; i < 3; i++){
        board[i] = new char[3];
        for (int j = 0; j < 3; j++)  {
            board[i][j] = '_';
        }
    }
    fillBoard();
}

void fillBoard(char **board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = '_';
        }
    }
}

void printBoard(char **board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << "\t";
            if (i == 2)
                cout << "\n";
        }
    }
}

TicTacToe::~TicTacToe() {
    for (int i = 0; i < 3; i++){
        delete [] board[i];
    }
    delete [] board;
    cout << "board destroyed" << endl;
}

bool boardFull(char **board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] = "_");
            return false;
        }
    }
    return true;
}

bool checkWin(char in, char **board) {
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == in && board[1][i + 1] == in && board[2][i]) {
            return true;
        } else if (board [i][0] == in && board[i][1] == in && board[i][2] == in)
            return true;
        else if (board[0][0] == in && board[1][1] == in && board[2][2] == in)
            return true;
        return false;
    }
}

void personPlay(char in, char **board) {
    cout << in << "'s turn" << endl;
    int row;
    int col;
    bool isEmpty = false;
    while (!isEmpty) {
        cout << "please input a row!" << endl;
        cin >> row;
        cout << "please input a column!" << endl;
        cin >> col;
        if (board[row][col] == "_") {
            isEmpty = true;
        }
    }
    board[row][col] = in;
    printBoard(board);
}

void playGame(char ** board) {
    bool isDone = false;
    while (!isDone) {
        personPlay('x',board);
        if (checkWin('x', board))
            break;
        if (boardFull(board))
            break;
        personPlay('o', board);
        if (checkWin('o', board))
            break;
        if (boardFull(board))
            break;
    }
    if (checkWin('x', board))
        cout << "Player " << 1 << " wins!" << endl;
    else if (checkWin('o', board))
        cout << "Player " << 2 << " wins!" << endl;
    if (boardFull(board))
        cout << "It's a tie!" << endl;
}