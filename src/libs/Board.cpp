#include "Board.h"
#include <iostream>

using namespace std;

Board::Board(int x,int y,int winLineLeng) 
: x(x), y(y), winLineLen(winLineLeng) {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            this->board[i][j] = '.';
        }
    }
}

void Board::place(int x,int y, char player) 
{
    if (this->board[x][y] == '.') {
        this->board[x][y] = player;
    }
}

void Board::print() {
    for (int i = 0; i <= this->x; i++) {
        for (int j = 0; j <= this->y; j++) {
            if ((i == 0) && (j == 0)) cout << ' ' << ' ';
            else if ((i == 0) && (j != 0)) printf("%2d",j);
            else if ((i != 0) && (j == 0)) printf("%2d",i);
            else cout << this->board[i-1][j-1] << ' ';
            cout << '|';
        }
        cout <<'\n';
        for (int j = 0; j <= this->y; j++) {
            cout << '=' << '=' << ' ';
        }
        cout << '\n';

    }
}

bool Board::checkWin() {
    int counthor = 0, countver = 0, countdiag = 0, countcontrdiag = 0;
    for (int i = 0; i < this->x; i++) {
        for (int j = 0; j < this->y; j++) {
            if (!(this->checkNotPlaced(i,j))) {
                // some checker for this->WinLineLen 
                for (int pat = 0; pat < this->winLineLen; pat++) {
                    if ((i+pat) < this->x) {
                        if (this->board[i][j] == this->board[i+pat][j]) {counthor++;
                        // cout << "hor " << counthor << endl;
                        }}
                    if ((j+pat) < this->y) {
                        if (this->board[i][j] == this->board[i][j+pat]) {countver++;
                        // cout << "ver " << countver << endl;
                        }}
                    if (((i+pat) < this->x) & ((j+pat) < this->y)) {
                        if (this->board[i][j] == this->board[i+pat][j+pat]) {countdiag++;
                        // cout << "diag " << countdiag << endl;
                        }}
                    if (((i-pat) >= 0) & ((j-pat) >= 0)) {
                        if (this->board[i][j] == this->board[i-pat][j-pat]) {countcontrdiag++;
                        // cout << "contr " << countcontrdiag << endl;
                        }}
                if ((counthor == this->winLineLen) || (countver == this->winLineLen) || (countdiag == this->winLineLen) || (countcontrdiag == this->winLineLen)) {
                    this->print();
                    return true;}
                }
                counthor = 0, countver = 0, countdiag = 0, countcontrdiag = 0;
            }
            fflush(stderr);
        }
    }
    return false;
}

bool Board::checkNotPlaced(int x,int y) {
    return (this->board[x][y] == '.');
}