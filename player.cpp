#include <cstdlib>
#include "player.h"
#include <iostream>

// Add item to player's inventory
void player::addItem(Item* item, read_player* turn) {turn->hand.push_back(item);}

void player::showItems(read_player* turn){
    int count = 0;
for(auto& item : turn->hand){ std::cout << "Slot" << count << item->getName() << std::endl; count++;}
}

void player::useitem(int slot, read_player* turn) {
    if (slot < 0 || slot > 4 || turn->hand[slot] == nullptr) {std::cout << "NO ITEM IN SLOT OR SLOT DOESN'T EXISTED. PLEASE CHOOSE AGAIN\n";return;}
    std:: cout << "use" << turn->hand[slot]->getName();
    turn->hand[slot]; turn->hand[slot] = nullptr;
}

void player::draw_random_item(read_player* player){




}

// Display items
// void player::showItems() const {
//     std::cout << name << " has items: ";
//     if (items.empty()) {
//         std::cout << "(none)\n";
//     } else {
//         for (size_t i = 0; i < items.size(); ++i) {
//             std::cout << items[i]->getName();
//             if (i < items.size() - 1) std::cout << ", ";
//         }
//         std::cout << "\n";
//     }
// }
