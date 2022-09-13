#include<iostream>
using namespace std;

class Base{
    public:
    int x=1;

    void change(){
        x++;
    }
};

class Derived: public Base{
    public:

    // overriding a Base method, just use the same signature
    void change(){
        x--;
    } 
};

int main(void){
    Base b;
    Derived d;

    b.change();
    cout << b.x << "\n";

    d.change();
    cout << d.x << "\n";
}