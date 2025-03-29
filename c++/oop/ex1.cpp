#include <iostream>
using namespace std;

void create_class_and_display(){

    class Player{
        public:
        string name;
        int health;

    };

    Player p1;
    p1.name = "osama";

    cout << p1.name << "\n";
}


int main(void){

    create_class_and_display();
    
    /* you can create a class IN a function, BUT it will be usable only within the function */

    // Player p2; Error!
}