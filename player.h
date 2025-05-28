#pragma once
#include "Radom_Bullet.h"
#include "base_class.h"
#include "Item.h"



class player {
protected:; // Player's inventory
Item* obj = nullptr; // Current item being used
   
   
   gun* teacher_project_time = nullptr; // Gun object for the player
   
   read_player* current_turn = nullptr;
   Radom_Bullet projectime;
   std::vector<Item*> possible_random_item = {
        new double_damage(current_turn),
        new healItem(current_turn),
        new skip_turn(current_turn),
        new scan_bullet(current_turn,projectime.gun_socket) 
    };
public:
int state_switching = 0;
player(){teacher_project_time = projectime.gun_socket;}; // Default constructor



void set_turn (read_player* play) {
   current_turn = play; 
   possible_random_item[0]->current_turn = play;
   possible_random_item[1]->current_turn = play;
   possible_random_item[2]->current_turn = play; 
   possible_random_item[3]->current_turn = play;}; // Set the current player

Radom_Bullet* get_projectime() {return &projectime;}

read_player* get_turn() {return current_turn;}

gun* get_gun() {return teacher_project_time;}

void addItem(Item* item); // เพิ่มไอเท็มลงใน inventory

void showItems(); //แสดงไอเท็มใน inventory

void useitem(int slot); //ใช้ไอเท็มจาก inventory

void shoot(bool entity); //ยิงกระสุน

void draw_random_item(); //สุ่มไอเท็ม

void show_status(); //แสดงสถานะของผู้เล่น game display

void show_next_bullet(); //แสดงกระสุนถัดไป  
// void show_next_bullet(bool  ); //แสดงกระสุนถัดไป
void clear_game_data(); //ล้างหน้าจอเกม
};




