#include <iostream>
using namespace std;

class Player{
    public:
    int health;
    string name;

    Player(int h, string n) : health{h}, name{n}{}

    /* an example of a copy constructor */
    /* parameter is const, as we want to copy it, no modification */
    Player(const Player &source) : health{source.health}, name(source.name){}
};


int main(void){
    Player p1(50, "p1");
    Player p2 {p1};

    cout << p2.health << " " << p2.name << "\n";
}