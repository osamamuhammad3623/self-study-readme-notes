#include<iostream>
using namespace std;

class Base{
public:
    int x=15;
};

class Derived: Base{
    public:
    int x = 10;

    int get_base_x(){
        return Base::x;
        /* to access an attribute in base class that has the same as derived class,
            use Specifiers (::) 
        */
    }
};

int main(void){
    Derived d;

    cout << d.x << "\n"; // x in the Derived class
    cout << d.get_base_x() << "\n"; // x in the Base class

}