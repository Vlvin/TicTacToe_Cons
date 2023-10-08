#pragma once

#include <string>
using namespace std;

class Player
{
    private:
        char pn;
        string name;
    public:
        Player();
        Player(char pn, string name);
        
        string getName();
        char getSymb();
        
        void Init(string name, char pn);
        static int playerCount;
        
};