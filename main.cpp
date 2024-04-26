//Samantha 25/04/24

#include <iostream>
#include "Enemy/Enemy.h"
#include "Player/Player.h"
#include "Combat/Combat.h"
#include <queue>

using namespace std;

int main() {
    Player *player = new Player("Sam", 30, 8, 2, 10);
    Enemy *enemy = new Enemy("Programacion", 30, 9, 2, 7);
    Enemy *enemy2 = new Enemy("Calculo", 30, 7, 2, 2);

    vector<Character*> participants;
    participants.push_back(player);
    participants.push_back(enemy);
    participants.push_back(enemy2);

    Combat* combat = new Combat(participants);
    combat->doCombat();

    delete player;
    delete enemy;
    delete enemy2;
    delete combat;

    return 0;
}