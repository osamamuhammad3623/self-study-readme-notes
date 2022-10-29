#include<iostream>
using namespace std;

class Player{
    private:
    string name{"x"};
    int health;
    friend string get_player_name(const Player &player);
    int get_player_health(const Player &player);
};

/* this function can NOT access the private attributes in the class
    UNLESS in is declared in the class as a friend method */
string get_player_name(const Player &player){
    return player.name;
}

int get_player_health(const Player &player){
    //return player.health; Error!
}

int main(void){
    Player p1;
    cout << get_player_name(p1) << "\n";
}