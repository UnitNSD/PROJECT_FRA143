#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "base_class.h"



class player {
private:
   std::vector<Item*> possible_random_item;
public:
player() = default; // Default constructor
void addItem(Item* item, read_player* turn);
void showItems(read_player* turn);
void useitem(int slot, read_player* turn);
void shoot(read_player* player,std::vector<bool> bullet);
void draw_random_item(read_player* player);
#endif

};
