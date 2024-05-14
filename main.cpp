//Samantha 13 DE MAYO 2024

#include <iostream>
#include "Enemy/Enemy.h"
#include "Player/Player.h"
#include "Combat/Combat.h"
#include <queue>


using namespace std;

int main();

int main() {
    Player *player = new Player("Samantha", 50, 10, 2, 10, 20, 14);
    Enemy *enemy = new Enemy("Programacion", 20, 9, 2, 7, 20, 15);
    enemy ->setWinEnemy(45);

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
