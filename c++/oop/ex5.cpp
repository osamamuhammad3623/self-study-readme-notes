#include <iostream>
using namespace std;

class Player{
    public:
    int health;
    string name;

    Player(string n, int h){
        /* The following is just assigning new values to already created attribute */
        
        /*
        When you create a Player object, the attributes Name and Health are INITIALIZED
        with garbage values, then they are assigned new values in the constructor!
        so, there are 2 steps: initialization with garbage values, then assigning new values.
        */

        cout << health << " " << name << "\n";
        name = n;
        health=h;
    }


    /*
    Using "Initialization List" is better, as attributes are initialized with given values!
    so this is only one step: initialization with given values!
    */
    Player(int h, string n) : health{h}, name{n}{
        cout << health << " " << name << "\n";
    }

};

int main(){
    Player p1("p1", 75);
    Player p2(50, "p2");
    // debug the code!
}

