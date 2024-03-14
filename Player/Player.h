//
// Created by preci on 14/03/2024.
//

#ifndef PPROYECTO_PARCIAL_RPG_PLAYER_H
#define PPROYECTO_PARCIAL_RPG_PLAYER_H
#include "../Character/Character.h"
#include "../Enemy/Enemy.h"
#include "../Combat/Action.h"

struct Action;
class Enemy;

class Player: public Character {
protected:
    int experience;
    int level;
public:
    Player(string _name, int _health, int _attack, int _defense, int _speed);
    void doAttack(Character *target) override;
    void takeDamage(int damage) override;

    Character* getTarget(vector<Enemy*> enemies);

    void flee(vector<Enemy*> enemies);
    void emote();
    void levelUp();
    void gainExperience(int);

    //Podemos hacer que este vector sea polimorfico?
    Action takeAction(vector<Enemy*> enemies);

};


#endif //PPROYECTO_PARCIAL_RPG_PLAYER_H