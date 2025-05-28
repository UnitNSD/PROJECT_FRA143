#ifndef RADOM_BULLET_H
#define RADOM_BULLET_H

#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include "base_class.h"

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */

/*เขียน random bulletโดยที่ให้สุ่ม bullet ก่อนแล้วค่อยเขียน funtion มาอ่าน bullet return ออกมา */

class Radom_Bullet {
public:
    std::vector<std::string> shell = {
    ".----.______   ",
    "|mga        |  ",
    "|   ___________",
    "|  /          /",
    "| /          / ",
    "|/__________/  "
};
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


    void printShells() {
        int pass = gun_socket->pass;
        int retake = gun_socket->retake;
        const std::vector<std::string>shellTemplate = shell;
        const std::string spacing = "   ";

        // Step 1: Normalize shell line widths
        size_t maxLen = 0;
        for (const std::string& line : shellTemplate) {
            if (line.length() > maxLen)
                maxLen = line.length();
        }

        std::vector<std::string> uniformShell;
        for (const std::string& line : shellTemplate) {
            std::string padded = line;
            padded.resize(maxLen, ' ');
            uniformShell.push_back(padded);
        }

        // Step 2: Create color pattern (retake -> RED, pass -> CYAN)
        std::vector<std::string> colors;
        colors.insert(colors.end(), retake, RED);
        colors.insert(colors.end(), pass, CYAN);

        // Step 3: Print shells in one aligned row
        for (size_t line = 0; line < uniformShell.size(); ++line) {
            for (const std::string& color : colors) {
                std::cout << color << uniformShell[line] << RESET << spacing;
            }
            std::cout << std::endl;
        }
    }
}
;


#endif 