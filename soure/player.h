#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "Item.h"


struct read_player{
    std::string name;
    int hp;
    int handcuff; 
    std::vector<Item*> items;
    read_player *next_turn; 
};

class player {
private:
    
public:
    player(const std::string& n);
    void addItem(Item* item);
    void showItems() const;

};

#endif


