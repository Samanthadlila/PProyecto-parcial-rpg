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

Player::Player(string name, int health, int attack, int defense, int speed) : Character(name, health, attack, defense,
                                                                                        speed, true) {
    experience = 0;
    level = 1;
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

void Player::flee(vector<Enemy *> enemies) {
    std::sort(enemies.begin(), enemies.end(), compareSpeed);
    Enemy *fastestEnemy = enemies[0];
    bool fleed = false;
    if (this->getSpeed() > fastestEnemy->getSpeed()) {
        fleed = true;
    } else {
        srand(time(NULL));
        int chance = rand() % 100;
        cout << "chance: " << chance << endl;
        fleed = chance > 99;
    }

    this->fleed = fleed;
}

void Player::emote() {
    cout << "Jokes on you" << endl;
}

void Player::levelUp() {
    level++;
    setHealth(getHealth() + 10);
    setAttack(getAttack() + 5);
    setDefense(getDefense() + 5);
    setSpeed(getSpeed() + 5);
}

void Player::gainExperience(int exp) {
    experience += exp;
    if (experience >= 100) {
        levelUp();
        experience = 0;
    }
}

Character *Player::getTarget(vector<Enemy *> enemies) {
    cout << "Elige un objetivo:  " << endl;
    int targetIndex = 0;
    for (int i = 0; i < enemies.size(); i++) {
        cout << i << ". " << enemies[i]->getName() << endl;
    }
    cin >> targetIndex;
    //TODO: Add input validation
    return enemies[targetIndex];
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
