#include "Player.h"
#include "Item.h"
#include "Radom_Bullet.h"
#include <iostream>
#include <cstdlib>
#include <unistd.h> //หน่วงเวลา




void game() {
    int universal_check = 1;
    int round = 0;
    player console;
    std::cout << YELLOW << "__________________________________________________________" << RESET << "\n";    
    std::cout << "  Welcome to FIBO Roulete!!!\n";
    read_player* player1 = new read_player("Student 1");
    read_player* player2 = new read_player("Student 2");



    // Get player names
    std::cout << "Enter your name player 1: ";
    std::cin >> player1->name;
    sleep(0.5);
    std::cout << "Enter your name player 2: ";
    std::cin >> player2->name;
    sleep(0.5);



    // draw initial items for both players
    console.set_turn(player1);
    console.draw_random_item();
    console.draw_random_item();
    sleep(1);

    console.set_turn(player2);
    console.draw_random_item();
    console.draw_random_item();
    sleep(1);   

    // Link players for turn switching
    player1->next_turn = player2;
    player2->next_turn = player1;



    //Random starting player
    srand(time(0));
    int random_start = rand() % 2;
    if (random_start == 1) {
        console.set_turn(player1);
    } else {
        console.set_turn(player2);
    }
    //Announce starting player
    std::cout << YELLOW << "__________________________________________________________" << RESET << "\n";
    std::cout << "Player " << console.get_turn()->name << " starts First!\n";
    std::cout << "START GAME!!!\n";





    // Main game loop
    while (player1->hp > 0 && player2->hp > 0) { // Continue until one player loses
        std::cout << YELLOW << "__________________________________________________________" << RESET << "\n";
        std::cout << "Round: " << ++round << "\n" ;
        std::cout << "Reloading gun...\n";

        // Reload the gun when ammo out with random bullets
        console.get_projectime()->Radom_Ammout_Bullet(); // Randomly set the number of bullets
        console.get_projectime()->Radom_In_cartridge(); // Randomly fill the cartridge with bullets
        console.get_projectime()->print_type_ammo(); // Print the type of bullets in the cartridge
        console.get_projectime()->printShells();
        console.set_turn(console.get_turn()->next_turn); // Switch to the next player
       
       
        console.draw_random_item(); // Draw a random item for the playerol
        console.draw_random_item(); // Draw a random item for the playerol
        console.set_turn(console.get_turn()->next_turn); // Switch to the next player
        console.draw_random_item(); // Draw a random item for the playerol
        console.draw_random_item(); // Draw a random item for the playerol
        
        
        while (console.get_gun()->cartridge.size() > 1) {

        console.show_status(); // show state of that player have

        if (console.get_turn()->handcuff == false) {
        // ยิงหรือใช้ไอเท็ม
        universal_check = 1; // Reset universal_check for the next action

    while (console.state_switching == 0) {
        console.state_switching = 0;
        std::cout << YELLOW << "Use your item or shoot? (use[1]/shoot[2]): " << RESET;
        int choice_fight;
        std::cin >> choice_fight;

        switch (choice_fight) {
            case 1: {
                int item_index;
                std::cout << YELLOW << "Enter the index of the item you want to use (enter index): " << RESET;
                std::cin >> item_index;
                console.useitem(item_index);
                break;
            }
            case 2: {
                std::cout << YELLOW << "Who do you want to shoot? (yourself[1]/opponent[2]): " << RESET;
                int choice_shoot;
                std::cin >> choice_shoot;
                switch (choice_shoot) {
                    case 1:
                        console.shoot(true); // Shoot yourself
                        break;
                    case 2:
                        console.shoot(false); // Shoot opponent
                        break;
                    default:
                        std::cout << RED << "!Invalid target. Please try again!" << RESET << "\n";
                        break; // Ask again
                }
                break;
            }
            default:
                std::cout << RED << "!Invalid target. Please try again!" << RESET << "\n";
                break; // Ask again
    }
    if(console.state_switching == 1) {
    console.set_turn(console.get_turn()->next_turn);} // Switch turn
    std::cout << YELLOW << "__________________________________________________________" << RESET << "\n";
    std::cout << "Next turn: " << console.get_turn()->name << "\n";
    console.state_switching = 0; // Reset state_switching for the next turn
    break; // Exit the while loop after a valid action
}
        } else {
            std::cout << "You got W gread and cannot take action this turn.\n";
            std::cout << YELLOW << "__________________________________________________________" << RESET << "\n";
            console.get_turn()->handcuff = false; // Reset handcuff status for the next turn
            console.set_turn(console.get_turn()->next_turn); // Switch to the next player
        }

        // Check if any player has lost
        if (player1->hp <= 0) {
            std::cout << YELLOW << "__________________________________________________________" << RESET << "\n";
            std::cout << RED << player1->name << " has lost the game!" << RESET << "\n";
            break;
        } else if (player2->hp <= 0) {
            std::cout << YELLOW << "__________________________________________________________" << RESET << "\n";
            std::cout << RED << player2->name << " has lost the game!" << RESET << "\n";
            break;
        }
    }
}       
console.clear_game_data(); // Clear game data after the game ends
    std::cout << YELLOW << "__________________________________________________________" << RESET << "\n";
    std::cout << CYAN << "Thanks for playing!" << RESET << "\n";        
    } 


int main() {
    std::srand(std::time(0));
    std::cout << "Working\n";
    game();
    return 0;
}
