#include<iostream>
using namespace std;

class Base{
    public:
    Base(){
        cout << "Base constructor is called\n";
    }

    ~Base(){
        cout << "Base destructor is called\n";
    }
};

class Derived: public Base{
    public:
    Derived(){
        cout << "Derived constructor is called\n";
    }

    ~Derived(){
        cout << "Derived destructor is called\n";
    }
};

int main(){

    /*
    in constructing, Base constructor is called BEFORE Derived constructor
    in destructing,  Derived destructor is called BEFORE Base destructor 
    */


    cout << "*********Base object**********\n";
    Base b;

    cout << "*********Derived object**********\n";
    Derived d;
}