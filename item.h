#pragma once
#ifndef ITEM_H
#define ITEM_H

#include <string>
#include "base_class.h"
#include "Radom_Bullet.h"
class Item {
public:
    // virtual destructor สำหรับ base class Item ลบ class สืบทอดตัวอื่น    

    read_player* current_turn = nullptr; // ตัวแปรสำหรับเก็บผู้เล่นปัจจุบัน
    gun* current_gun = nullptr; // ตัวแปรสำหรับเก็บปืนปัจจุบัน
    Item(read_player* player){current_turn = player;} // Constructor เริ่มต้น
    Item(read_player* player, gun* project_time) {current_turn = player, current_gun = project_time;} // Constructor เริ่มต้น
    virtual ~Item() {}
    virtual std::string getName() const = 0;
    virtual void use() = 0; // ฟังก์ชันใช้ item
};

//คูณดาเมจ 2 เท่าเวลายิง
class double_damage : public Item{
public:
    double_damage(read_player* player) : Item(player) {} // Constructor เริ่มต้น
    void use() override {current_turn->double_damage = true;}
    std::string getName() const override { return "Emotional Damage"; }
};


//ฮีลเลือก เพิ่ม hp (+1) ทันที
class healItem : public Item {
public:
    healItem(read_player* player) : Item(player) {} // Constructor เริ่มต้น
    void use() override {current_turn->hp += 1;}
    std::string getName() const override { return "Energy Boost"; }
};


//ใบ้ฝั่งตรงข้าม
class skip_turn : public Item {
public:
    skip_turn(read_player* player) : Item(player) {} // Constructor เริ่มต้น
    void use() override {current_turn->next_turn->handcuff = true;}
    std::string getName() const override { return "W Grade"; }
};

class scan_bullet : public Item {
public:
    scan_bullet(read_player* player, gun* project_time) : Item(player, project_time) {} // Constructor เริ่มต้น
    void use() override {
        int read_bullet = current_gun->cartridge[0];
        if (read_bullet == 0) {
            std::cout << "The next bullet is safe! (0 damage)\n";
        } else {
            std::cout << "The next bullet is dangerous! (1 damage)\n";
        }
    }
    std::string getName() const override { return "See the future"; }
};

// std::string getName() const override {return "See the future";}



#endif

