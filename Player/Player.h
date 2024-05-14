//
// Created by preci on 14/03/2024.
//

#ifndef PPROYECTO_PARCIAL_RPG_PLAYER_H
#define PPROYECTO_PARCIAL_RPG_PLAYER_H
#include "../Character/Character.h"
#include "../Enemy/Enemy.h"
#include "../Combat/Action.h"

using namespace std;

struct Action;
class Enemy;

class Player: public Character {

    char* buffer{}; //variable de paso

public:
    Player(char* _name, int _health, int _attack, int _defense, int _speed, int _experience, int _level);
    void doAttack(Character *target) override;
    void takeDamage(int damage) override;
//    void gainExperience(Enemy* enemy);////?????????????


    char* serialize();//serializa la instancia de la clase que tenemos
    void LevelUp();

    Character* getTarget(vector<Enemy*> enemies);
    void flee(vector<Enemy*> enemies);
    void emote();
    Action takeAction(vector<Enemy*> enemies);


};

//Intento num1 ///////
    //void gainExperience(int exp) {
    //     experience += exp;
    //    if (experience >= 100) {
    //        levelUp();
    //        experience = 0;
    //    }
    // }

    // void levelUp() {
    //    level++;
    //    cout << "Congratulations! You've reached level " << level << "!\n";
    //}

    //int getLevel() const {
    //    return level;
    //}
//};





#endif //PPROYECTO_PARCIAL_RPG_PLAYER_H