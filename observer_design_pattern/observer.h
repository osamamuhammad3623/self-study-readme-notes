#ifndef OBSERVER
#define OBSERVER

#include <vector>
#include <iostream>
using namespace std;

/* Interface class for observer */
class ObserverInterface{
public:
    virtual void update(void)=0;
};

/* Concrete class for observer */
class SomeObserver: public ObserverInterface{
    string name;
public:
    void update(void);
    SomeObserver(string _name);
};
#endif