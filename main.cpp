//Samantha 10 DE MAYO 2024

#include <iostream>
#include "Enemy/Enemy.h"
#include "Player/Player.h"
#include "Combat/Combat.h"
#include <queue>
////////////////////////CAMBIOS
using namespace std;

int main();

int main() {
    Player *player = new Player("Samantha", 30, 8, 2, 10, 20, 14);
    Enemy *enemy = new Enemy("Programacion", 30, 9, 2, 7, 20, 15);

    vector<Character*> participants;
    participants.push_back(player);
    participants.push_back(enemy);

    Combat* combat = new Combat(participants);
    combat->doCombat();

    delete player;
    delete enemy;
    delete combat;

    return 0;
}
