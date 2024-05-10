//
// Created by preci on 14/03/2024.
//

#ifndef PPROYECTO_PARCIAL_RPG_CHARACTER_H
#define PPROYECTO_PARCIAL_RPG_CHARACTER_H
#include <string>
#include "../Combat/Action.h"

using namespace std;

class Character {
public:
    Character(char *_name, int _health, int _attack, int _defense, int _speed, bool _isPlayer, int _experience,
              int _level);

    char name[30];
    int health;
    int attack;
    int defense;
    int speed;
    bool isPlayer;
    bool fleed;
    int experience;

    int level;


public:
    Character(char*, int, int, int, int, bool);//cambio a char

    virtual void doAttack(Character *target) = 0;
    virtual void takeDamage(int damage) = 0;

    void setName(char* );//cambio a char

    char* getName();//cambio a char

    void setHealth(int);
    int getHealth();
    void setAttack(int);
    int getAttack();
    void setDefense(int);
    int getDefense();
    void setSpeed(int);
    int getSpeed();
    char toString();
    bool getIsPlayer();
    bool hasFleed();
    int getExperience();
    int getLevel();

};


#endif //PPROYECTO_PARCIAL_RPG_CHARACTER_H
