#include<iostream>
using namespace std;

class Base{
    public:
    int base_attr;

    Base() : base_attr{}{}

    Base(int i){
        base_attr = i;
    }

    ~Base(){}
};

class Derived: public Base{
    public:
    int derived_attr;

    Derived() : derived_attr{}{}

    /*
    if the with-arg constructor is not called explicilty,
        the no-arg constructor is called automatically
    */

    /* to call a specific Base constructor explicitly: */
    Derived(int b_attr, int d_attr) : Base(b_attr){
        derived_attr=d_attr;
    }

    /* this will call the no-arg constructor automatically */
    Derived(int d_attr){
        derived_attr = d_attr;
    }

    ~Derived(){}
};

int main(void){
    
    Derived d{5,12};
    cout << "===Calling the Base contructor explicilty\n";
    cout << "Base attribute: " << d.base_attr << "\n";
    cout << "Derived attribute: " << d.derived_attr << "\n";

    Derived dd{20};
    cout << "===Calling the Base contructor automatically\n";
    cout << "Base attribute: " << dd.base_attr << "\n";
    cout << "Derived attribute: " << dd.derived_attr << "\n";
}