#pragma once
#include <iostream>
#include "Player.cpp"
#include "Item.h"
#include "Radom_Bullet.h"

int main() {
// Set up game
    read_player* player1 = new read_player("Student 1");
    read_player* player2 = new read_player("Student 2");
    player1->next_turn = player2;
    player2->next_turn = player1; 
    std::cout << "Enter your name player 1: ";
    std::cin >> player1->name;
    std::cout << "Enter your name player 2: ";
    std::cin >> player2->name;


//     while (player1->hp > 0 && player2->hp > 0) 

    return 0;
}