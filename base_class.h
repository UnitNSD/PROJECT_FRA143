#pragma once
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
// #include "item.h"
class Item; // Forward declaration of Item class
struct read_player{
    std::string name;
    int hp;
    bool handcuff;
    bool double_damage;
    std::vector<Item*> hand = {nullptr,nullptr,nullptr,nullptr,nullptr}; //ห้ามใช้ push_back เพราะจะทำให้เกิดการเปลี่ยนแปลงขนาดของ vector
    read_player *next_turn  =  nullptr;
    read_player(const std::string& n, int health = 5, bool cuffs = false , bool add_damage = false): name(n)
    , hp(health), handcuff(cuffs) , double_damage(add_damage) {}
};

struct gun{
    int amount_bullet = 0; // total bullet in gun
    int pass = 0; // zero damage bullet
    int retake = 0; // one damage bullet
    std::vector<int> cartridge = {};
};