#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "Item.h"

class player {
private:
    std::string name;
    int hp;
    int handcuff; 
    std::vector<Item*> items;


public:
    player(const std::string& n);
    void addItem(Item* item);
    void showItems() const;
};

#endif


