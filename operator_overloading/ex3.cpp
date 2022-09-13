#include<iostream>
using namespace std;

class Player{

    string name;
    int health;
    
public:
    Player(){}
    Player(string n, int h) : name{n}, health{h}{}
    // define the function as (friend) to allow it to access non-public data members
    friend ostream &operator<<(ostream &os, const Player &player);
};

/* output stream */
ostream &operator<<(ostream &os, const Player &player){
    os << "Player name: " << player.name << ", health: " << player.health << "\n";
}

/* input stream */
istream &operator>>(istream &is, Player &player){
    string n; int h;
    is >> n >> h;
    player = Player(n,h);
    return is;
}

int main(void){

    Player p1{"Osama", 99};
    cout << p1;

    Player p2;
    cin >> p2; // you enter the name, then health
    cout << p2;
}