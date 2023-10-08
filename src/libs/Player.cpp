#include "Player.h"
#include <string>

using namespace std;

Player::Player() {
    this->name = "NULL";
    this->pn = NULL;
}

Player::Player(char pn, string name):
    pn(pn), name(name) {}

string Player::getName() {
    
    return this->name;
}
void Player::Init(string name, char pn) {
    if ((this->name == "NULL") && (this->pn == NULL)) {
        this->name = name;
        this->pn = pn;
        playerCount++;
    }
}

int Player::playerCount = 0;

char Player::getSymb() {
    return this->pn;
}
