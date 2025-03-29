#include <iostream>
using namespace std;

class Player{
public:
    string name;
    int health{100};
};


int main(void){
    Player p1;
    cout << p1.health << "\n";

    // You can set default attribute values without the use of constructors
    // in C++11 
}