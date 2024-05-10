//
// Samantha 8 de mayo del 2024
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
    int enemyHealth;

public:


    Enemy(char[30] , int, int, int, int,int, int );
    void doAttack(Character *target) override;
    void takeDamage(int damage) override;
    Character* getTarget(vector<Player*> teamMembers);
    Action takeAction(vector<Player*> player);
};


#endif //PPROYECTO_PARCIAL_RPG_ENEMY_H