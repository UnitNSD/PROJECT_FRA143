#include <iostream>
#include "Player.h"
#include "Item.h"

int main() {
    player p1("Student fibo");
    
    p1.addItem(new healItem());
    p1.addItem(new skip_turn());
    p1.addItem(new scan_item());
    
    player p2("enermy");
    

    p1.showItems();
    
    return 0;
}