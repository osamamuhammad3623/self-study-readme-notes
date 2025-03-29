#include <iostream>
using namespace std;

class Player{
    private:
    int health;

    public:
    void set_heath(int h);
    int get_health();
};

void Player::set_heath(int h){
    this->health = h;
}

int Player::get_health(){
    return this->health;
}

int main(void){
    Player p1;
    p1.set_heath(100);
    cout << p1.get_health() << "\n";

    /*
    You can implement the methods OUTSIDE the class,
    but you must use scope resolution operator (::)
    */
}