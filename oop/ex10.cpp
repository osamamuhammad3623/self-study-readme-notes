#include<iostream>
using namespace std;

class Player{
    public:
    string name;
    int health;

    Player(): health{}, name{""}{}
    Player(int h, string n): health{h}, name{n}{}

    /* operator overloading syntax: Type &operator=(const Type &rhs)
        or:     Type &Type::operator=(const Type &rhs), if it's declared outside the class
    */

    // assignment operator overloading (deep copy) :
    Player &operator=(const Player &rhs){
        this->name = rhs.name;
        this->health = rhs.health;
    }
};

int main(void){
    Player p1{75, "Osama"};
    Player p2;
    p2 = p1; // same as: p2.operator=(p1);

    cout << p2.name << " " << p2.health << "\n";
}