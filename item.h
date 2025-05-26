#ifndef ITEM_H
#define ITEM_H

#include <string>
 
class Item {
public:
    // virtual destructor สำหรับ base class Item ลบ class สืบทอดตัวอื่น
    virtual ~Item() {}
    virtual std::string getName() const = 0;
};

//heal hp player
//int: hp แสดงว่าถ้าเลือก hp (+1)

class HealItem : public Item {
public:
    std::string getName() const override { return "Cigarette"; }
};

//skip turn player
//int: handcuff 
class hand_culf : public Item {
public:
    std::string getName() const override { return "hand_culf"; }
};

//chack the next bullet 
//bullet_now : int: bullet_now 
//buttet_attack: bool 
//if true take damage (hp: - 1) 
//if flase take damage(hp: 0 )no action

class scan_item : public Item {
public:
    std::string getName() const override { return "Magnifying_Glass"; }
};




#endif

