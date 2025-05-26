#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <ctime>

/*เขียน random bulletโดยที่ให้สุ่ม bullet ก่อนแล้วค่อยเขียน funtion มาอ่าน bullet return ออกมา */

struct Bullet_In_Round
{
   
    int pass = 0; // zero damage bullet
    int retake = 0; // one damage bullet
    
};

class Radom_Bullet {
public:
    int ammout_bullet = 0;
    std::vector<int> cartridge = {};
    void Radom_Ammout_Bullet(){
        srand(time(0));
        ammout_bullet = (rand() % 6)+5;
    }
    void Radom_In_cartridge(){
        srand(time(0)); 
        for(int i=0;i < ammout_bullet;i++){
            cartridge.push_back(rand() % 2);
        }
    }
    int Get_Ammout_Bullet() {return ammout_bullet;}
    int Get_Bullet(int Bullet_sequence){return cartridge[Bullet_sequence];}

    
};
