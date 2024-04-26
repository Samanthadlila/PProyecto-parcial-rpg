//
// Created by preci on 14/03/2024.
//

#include "Character.h"
#include <cstring>//biblioteca agregada
#include <sstream>
#include <iostream>

//el strcpy no esta permitido, le falara una biblioteca?
//*string tiene un metodo llamado c_str() que devuelve un puntero de tipo
//const char* a su memoria interna
//strcpy es una funcion que copia la cadena a un char*

Character::Character(char _name[30], int _health, int _attack, int _defense, int _speed, bool _isPlayer) {//cambio a char
    if(_name != nullptr) strcpy(name, _name);//////////////////////////////////
    health = _health;
    attack = _attack;
    defense = _defense;
    speed = _speed;
    isPlayer = _isPlayer;
    fleed = false;
}

void Character::setName(char _name[30]) {///cambio a char
    strcpy(name, _name);}


string Character::getName() {
    return name;
}

void Character::setHealth(int _health) {
    health = _health;
}

int Character::getHealth() {
    return health;
}

void Character::setAttack(int _attack) {
    attack = _attack;
}

int Character::getAttack() {
    return attack;
}

void Character::setDefense(int _defense) {
    defense = _defense;
}

int Character::getDefense() {
    return defense;
}

void Character::setSpeed(int _speed) {
    speed = _speed;
}

int Character::getSpeed() {
    return speed;
}

string Character::toString() {
    string _name(name, 30);//no se cambia
    return "Name: " + _name + "\nHealth: " + to_string(health) + "\nAttack: " + to_string(attack) + "\nDefense: " + to_string(defense) + "\nSpeed: " + to_string(speed);
}

bool Character::getIsPlayer() {
    return isPlayer;
}

bool Character::hasFleed() {
    return fleed;
}