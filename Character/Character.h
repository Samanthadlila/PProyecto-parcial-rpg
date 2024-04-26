//
// Created by preci on 14/03/2024.
//

#ifndef PPROYECTO_PARCIAL_RPG_CHARACTER_H
#define PPROYECTO_PARCIAL_RPG_CHARACTER_H
#include <string>
#include "../Combat/Action.h"

using namespace std;

class Character {
protected:
    char name[30]={'S', 'a', 'm'};
    int health;
    int attack;
    int defense;
    int speed;
    bool isPlayer;
    bool fleed;

public:
    Character(char[30], int, int, int, int, bool);//cambio a char

    virtual void doAttack(Character *target) = 0;
    virtual void takeDamage(int damage) = 0;

    void setName(char [30]);//cambio a char
    string getName();

    void setHealth(int);
    int getHealth();
    void setAttack(int);
    int getAttack();
    void setDefense(int);
    int getDefense();
    void setSpeed(int);
    int getSpeed();
    string toString();
    bool getIsPlayer();
    bool hasFleed();
};


#endif //PPROYECTO_PARCIAL_RPG_CHARACTER_H
