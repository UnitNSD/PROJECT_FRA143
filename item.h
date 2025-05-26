#ifndef ITEM_H
#define ITEM_H

#include <string>
#include "player.h"
 
class Item : public read_player{
public:
    // virtual destructor สำหรับ base class Item ลบ class สืบทอดตัวอื่น
    virtual ~Item() {}
    virtual std::string getName() const = 0;
    virtual void use() = 0; // ฟังก์ชันใช้ item
   
};

//heal hp player
//int: hp แสดงว่าถ้าเลือก hp (+1)
class double_damage : public Item{
public:
    void use() override {
        // Logic for using double damage item
    }
    std::string getName() const override { return "Emotional Damage"; }
};

class healItem : public Item {
public:

    std::string getName() const override { return "Energy Boost"; }
};

//skip turn player
//int: handcuff 
class skip_turn : public Item {
public:
    std::string getName() const override { return "W Grade"; }
};

//chack the next bullet 
//bullet_now : int: bullet_now 
//buttet_attack: bool 
//if true take damage (hp: - 1) 
//if flase take damage(hp: 0 )no action

class scan_item : public Item {
public:
    std::string getName() const override { return "See the future"; }
};




#endif

