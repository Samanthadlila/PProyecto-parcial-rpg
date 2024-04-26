//
// Created by preci on 14/03/2024.
//

#ifndef PPROYECTO_PARCIAL_RPG_ENEMY_H
#define PPROYECTO_PARCIAL_RPG_ENEMY_H
#include "../Character/Character.h"
#include "../Player/Player.h"
#include "../Combat/Action.h"

struct Action;
class Player;

class Enemy: public Character {
public:
    Enemy(string, int, int, int, int);

    Enemy(char *_name, int health, int attack, int defense, int speed);


    void doAttack(Character *target) override;
    void takeDamage(int damage) override;
    Character* getTarget(vector<Player*> teamMembers);
    Action takeAction(vector<Player*> player);
};


#endif //PPROYECTO_PARCIAL_RPG_ENEMY_H