#include<iostream>
using namespace std;

class Player{
    string name;
    int health;

public:
    Player() : health{}, name{"x"}{}

    string get_name(){
        return name;
    }

    /* a const function [can deal with const objects] */
    string get_const_name() const{
        return name;
    }

};

int main(void){
    const Player p1;

    /* calling a method on a const object produces an error, as the method MIGHT
        change the object 
    */
    //cout << p1.get_name() << "\n"; Error!


    /* so so solve this, we define the method as const method, 
        meaning it won't change the object 
    */
    cout << p1.get_const_name() << "\n";

    /* note that methods that change object attributes, 
        will produce an error if called on const objects
        i.e. p1.set_name("xx");
    */
}