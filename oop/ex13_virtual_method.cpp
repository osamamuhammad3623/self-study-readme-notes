#include <iostream>

using namespace std;

class Shape{
public:

    /* virtual */void draw(){
        cout << "drawing shape\n";
    }
};

class Circle: public Shape{
    void draw(){
        cout << "drawing circle\n";
    }
};


int main()
{
    Shape *sh = new Circle();
    /*
    if the method is NOT virtual:
        the compiler chooses the draw in super class, as it corresponds to
        the type of the pointer [pointer to Shape]
    
    if the method IS virtual:
        the compiler chooses the draw in child class, as it corresponds to
        the type of the object [Circle object]
    */
    /* Polymorphism enables you to write a higher level of abstraction. */
    sh->draw();
    return 0;
}
