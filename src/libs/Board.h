#pragma once
class Board {
    private:
        int x, y, winLineLen;
        char board[15][15];
    public:
        Board(int x,int y,int winLineLen);
        void place(int x,int y, char player);
        bool checkWin();
        void print();
        bool checkNotPlaced(int x,int y);
};