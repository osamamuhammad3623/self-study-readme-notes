#ifndef SUBJECT
#define SUBJECT

#include <vector>
#include <iostream>
#include "observer.h"
using namespace std;

/* Interface class for subject [observable] */
class SubjectInterface{
private:
    vector<ObserverInterface*> observers; // subscribers
public:
    virtual void set_state(string s)=0;
    void notify(void);
    void register_observer(ObserverInterface* new_observer);
    // remove_observer can also be implemented
};


/* Concrete class for subject */
class SomeSubject: public SubjectInterface{
private:
    string state;
public:
    // set the state of the subject & notify observers
    void set_state(string s);
};

#endif