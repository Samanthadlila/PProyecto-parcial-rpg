//
// Created by preci on 14/03/2024.
//

#include "Player.h"
#include <iostream>
#include "../Utils.h"

using namespace std;
using namespace combat_utils;

bool compareSpeed(Enemy *a, Enemy *b) {
    return a->getSpeed() > b->getSpeed();
}
//cambio
Player::Player(char name[30], int health, int attack, int defense, int speed, int experience, int level) : Character(name, health, attack, defense,
                                                                                        speed, true, experience, level) {
}

void Player::doAttack(Character *target) {
    int rolledAttack = getRolledAttack(getAttack());
    int trueDamage = target->getDefense() > rolledAttack ? 0 : rolledAttack - target->getDefense();
    target->takeDamage(trueDamage);
}

void Player::takeDamage(int damage) {
    setHealth(health - damage);
    cout << "You have taken " << damage << " damage" << endl;
    if (health <= 0) {
        cout << "You have died" << endl;
    }
}

void Player::flee(vector<Enemy*> enemies) {
    std::sort(enemies.begin(), enemies.end(), compareSpeed);
    Enemy *fastestEnemy = enemies[0];
    bool fleed = false;
    if (this->getSpeed() > fastestEnemy->getSpeed()) {
        fleed = true;
    } else {
        srand(time(NULL));
        int chance = rand() % 100;
        cout << "Puedes huir " << chance << endl;
        if (fleed = chance > 90) {
            fleed = true;
        } else {
            cout << "No puedes huir." << endl;
        }
    }

    this->fleed = fleed;

}

void Player::emote() {
    cout << "Jokes on you" << endl;
}

Character *Player::getTarget(vector<Enemy *> enemies) {
    cout << "Elige un objetivo:  " << endl;
    int targetIndex = 0;
    for (int i = 0; i < enemies.size(); i++) {
        cout << i << ". " << enemies[i]->getName() << endl;
    }
    cin >> targetIndex;

    return enemies[targetIndex];
}

//Experiencia
void Player::gainExperience(Enemy* enemy) {
    if (enemy && enemy->health <= 0) {
        experience += enemy->experience;
        LevelUp();
    }
}
////////

void Player::LevelUp() {
    while (experience >= 100) {
        level++;
        experience -= 100;

        int healthGain = 10;
        int attackGain = 5;
        int defenseGain = 5;
        health += healthGain;
        attack += attackGain;
        defense += defenseGain;
    }
}



Action Player::takeAction(vector<Enemy *> enemies) {
    int option = 0;
    cout << "Elige una opcion: (Huye mientras puedas)" << endl;
    cout << "1. Ataque" << endl;
    cout << "2. Huir" << endl;
    cin >> option;
    Character *target = nullptr;


    Action myAction;

    myAction.speed = this->getSpeed();
    myAction.subscriber = this;

    switch (option) {
        case 1:
            target = getTarget(enemies);
            myAction.target = target;
            //1.
            myAction.action = [this, target]() {
                doAttack(target);
            };
            break;
        case 2:
            myAction.action = [this, enemies]() {
                flee(enemies);
            };
            break;
        default:
            cout << "Opcion no valida." << endl;
            break;
    }

    return myAction;
}

char* Player::serialize() {//esto es serializar
    char* iterador = buffer;

    memcpy(iterador, name, sizeof name);
    iterador += sizeof name;

    memcpy(iterador, &health, sizeof health);
    iterador += sizeof health;

    memcpy(iterador, &attack, sizeof attack);
    iterador += sizeof attack;

    memcpy(iterador, &defense, sizeof defense);
    iterador += sizeof defense;

    memcpy(iterador, &speed, sizeof speed);
    iterador += sizeof speed;

    memcpy(iterador, &isPlayer, sizeof isPlayer);
    iterador += sizeof isPlayer;

    memcpy(iterador, &experience, sizeof experience);
    iterador += sizeof experience;

    memcpy(iterador, &level, sizeof level);

    return buffer;

}
