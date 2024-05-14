//
// Created by preci on 14/03/2024.
//

#include "Enemy.h"
#include <iostream>


using namespace std;

int getRolledAttack(int attack) {
    int lowerLimit = attack * .80;
    return (rand() % (attack - lowerLimit)) + lowerLimit;
}

Enemy::Enemy(char name[30], int health, int attack, int defense, int speed, int experience, int level) : Character(name, health, attack, defense, speed, false, experience, level) {
}

void Enemy::doAttack(Character *target) {
    int rolledAttack = getRolledAttack(getAttack());
    int trueDamage = target->getDefense() > rolledAttack ? 0 : rolledAttack - target->getDefense();
    target->takeDamage(trueDamage);
}



void Enemy::takeDamage(int damage) {
    setHealth(getHealth() - damage);
    if(getHealth() <= 0) {
        cout<<getName()<<" ha muerto "<<endl;
    }
    else {
        cout<<getName()<<" tiene " << damage << " de danio " << endl;
    }
}

Character* Enemy::getTarget(vector<Player *> teamMembers) {


    int targetIndex = 0;
    int lowestHealth = INT_MAX;
    for(int i=0; i < teamMembers.size(); i++) {
        if(teamMembers[i]->getHealth() < lowestHealth) {
            lowestHealth = teamMembers[i]->getHealth();
            targetIndex = i;
        }
    }

    return teamMembers[targetIndex];
}
/////////////////////////////////////
///Huida del enemigo//////////
Action Enemy::takeAction(vector<Player *> player) {
    Action myAction;
    myAction.speed = getSpeed();
    myAction.subscriber = this;



    Character* target = getTarget(player);
    srand(time(NULL));
    if (this->getHealth() < enemyHealth && rand() % 100 < 15){
        myAction.action = [this, target]() {
            this->fleed = true;
        };
    } else {
        myAction.target = target;
        myAction.action = [this, target]() {
            doAttack(target);
        };
    }
    return myAction;
}

