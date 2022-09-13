#include<iostream>
using namespace std;

class Player{
public:
    string name;
    int health;
    
    Player(string n, int h): name{n}, health{h} {}

    /* Operator overloading WITHIN the class itself */

    int operator+ (const Player &rhs){
        return (health + rhs.health);
    }

    int operator- (const Player &rhs){
        return (health - rhs.health);
    }

    bool operator< (const Player &rhs){
        return (health < rhs.health);
    }

    bool operator> (const Player &rhs){
        return (health > rhs.health);
    }

    // for global operator overloading, function takes both LHS and RHS objects 
    /* note: functions are defined as friends, to access private attributes */
    friend bool operator==(const Player &lhs, const Player &rhs);
    friend bool operator==(const Player &lhs, const Player &rhs);
};


/* Implement operator overloading a global functions */
bool operator== (const Player &lhs, const Player &rhs){
    return (lhs.health == rhs.health);
}

bool operator!= (const Player &lhs, const Player &rhs){
    return (lhs.health != rhs.health);
}


int main(void){
    Player p1{"Osama", 75};
    Player p2{"Muhammmad", 50};

    cout << "P1 + P2: " << p1+p2 << "\n";
    cout << "P1 - P2: " << p1-p2 << "\n";
    
    cout << "P1 > P2: " << (p1>p2) << "\n";
    cout << "P1 < P2: " << (p1<p2) << "\n";

    cout << "P1 == P2: " << (p1==p2) << "\n";
    cout << "P1 != P2: " << (p1!=p2) << "\n";
}