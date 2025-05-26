#include "player.h"
#include <iostream>

// Constructor
player::player(const std::string& n) : name(n), hp(5), handcuff(0) {}

// Add item to player's inventory
void player::addItem(Item* item) {
    if (items.size() < 5) {
        items.push_back(item);
    }
}

// Display items
void player::showItems() const {
    std::cout << name << " has items: ";
    if (items.empty()) {
        std::cout << "(none)\n";
    } else {
        for (size_t i = 0; i < items.size(); ++i) {
            std::cout << items[i]->getName();
            if (i < items.size() - 1) std::cout << ", ";
        }
        std::cout << "\n";
    }
}
