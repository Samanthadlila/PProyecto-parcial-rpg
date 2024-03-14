//
// Created by preci on 14/03/2024.
//

#ifndef PPROYECTO_PARCIAL_RPG_COMBAT_H
#define PPROYECTO_PARCIAL_RPG_COMBAT_H
#pragma once
#include "../Character/Character.h"
#include "../Player/Player.h"
#include "../Enemy/Enemy.h"
#include "Action.h"
#include <vector>
#include <string>
#include <queue>


class Combat {
private:
    //Realmente sigo necesitando este vector?
    vector<Character*> participants;
    vector<Player*> teamMembers;
    vector<Enemy*> enemies;
    //Priority queue de acciones
    priority_queue<Action> actions;

    void prepareCombat();
    Character* getTarget(Character* target);
    void registerActions();
    void executeActions();

    void checkParticipantStatus(Character* participant);
    void checkForFlee(Character* character);

public:
    Combat(vector<Character*> _participants);
    Combat(vector<Player*> _teamMembers, vector<Enemy*> _enemies);
    Combat();
    void addParticipant(Character *participant);
    void doCombat();
    string participantsToString();
};


#endif //PPROYECTO_PARCIAL_RPG_COMBAT_H
