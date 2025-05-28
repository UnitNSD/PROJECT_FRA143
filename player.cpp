#include "player.h"
#include "Item.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h> //หน่วงเวลา

// Add item to player's inventory
void player::addItem(Item* item) {
    for (int i = 0; i < 5; i++) {
        if (current_turn->hand[i] == nullptr) {
            current_turn->hand[i] = item;
            std::cout << current_turn->name << " has added " << item->getName() << " to your hand." << std::endl;
            return;
        }
    }
    std::cout << "Your hand is full! Cannot hold more than 5 items!!" << std::endl;
}

void player::showItems() {
    int count = 0;
    for (auto& item : current_turn->hand) {
        std::cout << "Slot " << count << ": ";
        if (item)
            std::cout << item->getName();
        else
            std::cout << "(empty)";
        std::cout << std::endl;
        count++;
    }
}

void player::useitem(int slot) {
    if (slot < 0 || slot > 4 || current_turn->hand[slot] == nullptr) {
        std::cout << "NO ITEM IN SLOT OR SLOT DOESN'T EXIST. PLEASE CHOOSE AGAIN\n";
        return;
    }
    std::cout << "Use " << current_turn->hand[slot]->getName() << std::endl;
    current_turn->hand[slot]->use();
    current_turn->hand[slot] = nullptr;
}

void player::draw_random_item() {
    // สุ่มไอเท็มจาก 4 ชนิด
    int random = std::rand() % possible_random_item.size();
    addItem(possible_random_item[random]);
}

void player::show_status() {
    std::cout << "Player: " << current_turn->name  ;
    std::cout << "  Health: " << current_turn->hp << "\n";
    std::cout << "double_damage: " << (current_turn->double_damage ? "Yes" : "No") << "\n";
    std::cout << "Items in hand:\n";
    for (int i = 0; i < current_turn->hand.size(); i++) {
        std::cout << "[" << i << "] ";
        if (current_turn->hand[i] == nullptr) {
            std::cout << "(empty)";
        } else {
            std::cout << current_turn->hand[i]->getName();
        }
        std::cout << std::endl;
    }
}

//action เลือกยิงตัวเองหรือฝั่งตรงข้าม
void player::shoot(bool entity) {// true = ตัวเอง, false = ฝั่งตรงข้าม
    // Implement shooting logic here
    if(entity == true) {
        if(teacher_project_time->cartridge[0] == 0){
            std::cout << "Click......... \n";  
            sleep(1); 
            std::cout << "Blankkkkk eiei\n";
            state_switching = 0;}
        else {
            std::cout << "Click......... \n";  
            sleep(1); 
            std::cout <<"\33[31mBangggggggggg\n\33[m";
            if(current_turn->double_damage == true){current_turn->hp -= 2;current_turn->double_damage = false; } // Reset double_damage after use
            else{ current_turn->hp -= 1; state_switching = 1; } // Set state_switching to 1 to indicate shooting action
        }
    }
    else {
        if(teacher_project_time->cartridge[0] == 0){
        std::cout << "Click......... \n" ;  
        sleep(1); 
        std::cout << "Blankkkkk eiei\n";}
        else {
            std::cout << "Click......... \n"; 
            sleep(1);
            std::cout << "\033[31mBangggggggggg\033[0m\n"; 
            if(current_turn->double_damage == true){current_turn->next_turn->hp -= 2;current_turn->double_damage = false; } // Reset double_damage after use
            else{ current_turn->next_turn->hp -= 1; } 
        }
        state_switching = 1; // Switch turn to the next player
    }
    teacher_project_time->cartridge.erase(teacher_project_time->cartridge.begin()); // Remove the first bullet from the cartridge
    }

void player::clear_game_data() {
    delete current_turn->next_turn; // Free the memory allocated for current_turn
    delete current_turn; // Free the memory allocated for current_turn
    for(auto& item : possible_random_item) {
        delete item; // Free the memory allocated for each item in possible_random_item
    delete teacher_project_time; // Free the memory allocated for teacher_project_time
    }
}

