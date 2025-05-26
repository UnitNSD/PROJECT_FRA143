#include <string>
#include <vector>
#include "Item.h"
struct read_player{
    std::string name;
    int hp;
    int handcuff;
    int double_damage; 
    std::vector<Item*> hand;
    read_player *next_turn  =  nullptr;
    read_player(const std::string& n, int health = 5, int cuffs = 0): name(n), hp(health), handcuff(cuffs) {}
};

// 