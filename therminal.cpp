#pragma once
#include <iostream>
#include "Player.cpp"
#include "Item.h"
#include "Radom_Bullet.h"

// Set up game
void game() {    
    std::cout << "Welcome to FIBO Roulete!!!\n";
    read_player* player1 = new read_player("Student 1");
    read_player* player2 = new read_player("Student 2");
    player1->next_turn = player2;
    player2->next_turn = player1; 
    std::cout << "Enter your name player 1: ";
    std::cin >> player1->name;
    std::cout << "Enter your name player 2: ";
    std::cin >> player2->name;
    while (player1->hp > 0 && player2->hp > 0) {
        std::cout << player1->name << "'s turn\n";
        Radom_Bullet bullet;
        bullet.Radom_Ammout_Bullet();
        bullet.Radom_In_cartridge();
        std::cout << "You have " << bullet.Get_Ammout_Bullet() << " bullets in your cartridge.\n";
        
        // Player 1's turn logic here
        // For example, player1->shoot(player2, bullet.cartridge);
        
        std::cout << player2->name << "'s turn\n";
        // Player 2's turn logic here
        // For example, player2->shoot(player1, bullet.cartridge);
    }
};
void start(){

}
int main() {
    game();

    return 0;
}