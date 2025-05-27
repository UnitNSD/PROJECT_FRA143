#ifndef RADOM_BULLET_H
#define RADOM_BULLET_H

#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include "base_class.h"

/*เขียน random bulletโดยที่ให้สุ่ม bullet ก่อนแล้วค่อยเขียน funtion มาอ่าน bullet return ออกมา */

class Radom_Bullet {
public:
    gun* gun_socket = nullptr;

    Radom_Bullet() {
        gun_socket = new gun;
    }

    //
    void print_type_ammo(){
        gun_socket->pass = 0; // reset pass count
        gun_socket->retake = 0; // reset retake count
        for(auto ammo : gun_socket->cartridge){
            if(ammo == 0){
                gun_socket->pass++;
            }else if(ammo == 1){
                gun_socket->retake++;
            }
        }
        std::cout << "Gun has " << gun_socket->pass << " zero damage bullets and " 
                  << gun_socket->retake << " one damage bullets." << std::endl;
    }
    //สุ่มจำนวนกระสุน
    void Radom_Ammout_Bullet(){
        gun_socket->amount_bullet = (rand() % 6) + 5; // 5 ถึง 10 นัด
    }

    //สุ่มกระสุนในรังเพลิง
    void Radom_In_cartridge(){
        gun_socket->cartridge.clear(); // เคลียร์ทุกครั้งที่เรียกใช้
        for (int i = 0; i < gun_socket->amount_bullet; i++) {
            gun_socket->cartridge.push_back(rand() % 2); // 0 หรือ 1
        }
    }

    //ดูจำนวนกระสุนสูงสุด (max bullet)
    int Get_Ammout_Bullet() { return gun_socket->amount_bullet; }

    //ดูกระสุนทั้งหมดในรังเพลิงว่านัดไหนยิงออกไม่ออก
    int Get_Bullet(int Bullet_sequence) { return gun_socket->cartridge[Bullet_sequence]; }

    //ดูกระสุนล่าสุด
    int Get_Current_Bullet() {
        if (!gun_socket->cartridge.empty()) {
            return gun_socket->cartridge.front();
        } else {
            std::cout << "No bullets in cartridge!" << std::endl;
            return -1;
        }
    }
};


#endif 