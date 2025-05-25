#include <iostream>
#include "Player.h"
#include "Item.h"

int main() {
    player p1("Player1");
    
    p1.addItem(new HealItem());
    p1.addItem(new hand_culf());
    p1.addItem(new scan_item());
    

    p1.showItems();
    
    return 0;
}
