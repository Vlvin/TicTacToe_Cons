#include <iostream>
#include <string>

#include "libs/Board.h"
#include "libs/Player.h"


using namespace std;


int main() {
        // user input main players init
    char plSymb;
    string plName;
    Player plarr[15];

    //     // first player
    cout << "Tic-Tac-Toe Console Edition\n\n";
    cout << "First player, enter your name: \n"; cin >> plName;
    cout << "Hello " << plName << "!\n";
    cout << "Enter character of your mark: \n"; cin >> plSymb;
    plarr[0].Init(plName,plSymb);
    cout << "OK, " << plName << ". Your char is " << plSymb << endl;

    //     // second player
    cout << "Second player, enter your name: \n"; cin >> plName;
    cout << "Hello " << plName << "!\n";
    cout << "Enter character of your mark: \n"; cin >> plSymb;
    plarr[1].Init(plName,plSymb);
    cout << "OK, " << plName << ". Your char is " << plSymb << endl;

    //     // user input additional players init
    string choice;
    cout << "Do you want to add more player? Y//n"; cin >> choice;
    for (int i = 0; i < choice.length(); i++) choice[i] = tolower(choice[i]);
    if ((choice == "yes") || (choice == "y")) {
        for (int i = 2; (choice == "yes") || (choice == "y") || (i != 15); i++) {
            cout << i << " player, enter your name: \n"; cin >> plName;
            cout << "Hello " << plName << "!\n";
            cout << "Enter character of your mark: \n"; cin >> plSymb;
            plarr[i].Init(plName,plSymb);
            cout << "OK, " << plName << ". Your char is " << plSymb << endl;
            cout << "Do you want to add more player? Y//n: "; cin >> choice;
        }
    }

        // user input board init
    int boardX, boardY, WinLineLen;
    cout << "How wide board you want to play?\n"; cin >> boardX;
    cout << "How wide board you want to play?\n"; cin >> boardY;
    cout << "How many marks in horisontal, vertical or diagonal line you want to win?\n"; cin >> WinLineLen;
    Board b1(boardX, boardY, WinLineLen);

        // gamevars
        int px, py;
        bool run = true;
        // game loop
        while(run) {
            for (int movm = 0; ((run) & (movm < Player::playerCount)); movm++) {
                // system("clear");
                b1.print();
                cout << plarr[movm].getName() << " Enter X coordinate of your next mark: "; cin >> py;
                cout << plarr[movm].getName() << " Enter Y coordinate of your next mark: "; cin >> px;
                if (b1.checkNotPlaced(px-1, py-1)) {b1.place(px-1,py-1,plarr[movm].getSymb()); 
                } else {movm--;}
                if (b1.checkWin()) {
                    cout << plarr[movm].getName() << " Wins!!!\n";
                    run = false;
                    }
            }

        }

    return 0;
}