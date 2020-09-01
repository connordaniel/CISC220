//
// Created by connor on 9/19/19.
//

class TicTacToe {
   char **board;
   int player1;
   int player2;

public:
    TicTacToe();
    void fillBoard();
    void printBoard();
    bool boardFull();
    bool checkWin();
    void personPlay();
    void playGame();
    ~TicTacToe();

};