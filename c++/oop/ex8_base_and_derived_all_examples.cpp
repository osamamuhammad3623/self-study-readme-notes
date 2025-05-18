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

    {
    cout << "======Base object======\n";
    Base b; // base constructor, then destructor
    }

    {
    cout << "======pointer to Base object======\n";
    Base *b; // nothing is called, you just allocated a memory but didn't create an object
    }

    {
    cout << "======pointer to Base object with heap allocation======\n";
    Base *b = new Base(); // base constructor only (destructor will be called when you delete the pointer)
    }

    {
    cout << "======Derived object======\n";
    Derived d;
    }
    
    {
    cout << "======pointer to Derived object======\n";
    Derived *d; // nothing is called
    }

    {
    cout << "======pointer to Derived object with heap allocation======\n";
    Derived *d = new Derived(); // base constructor, then derived constructors, no destructors
    }

    {
    cout << "======Polymorphism example======\n";
    Base *b = new Derived(); // only constructors are called
    }

    {
    cout << "======Polymorphism example 2======\n";
    Base b = Derived();
    }
}
