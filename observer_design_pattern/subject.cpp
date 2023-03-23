#include "subject.h"

/****************************
SubjectInterface implementation
****************************/  
void SubjectInterface::notify(void){
    for(ObserverInterface* ob: observers){
        ob->update();
    }
}

void SubjectInterface::register_observer(ObserverInterface* new_observer){
    observers.push_back(new_observer);
}


/****************************
SomeSubject implementation
****************************/ 
void SomeSubject::set_state(string s){
    state = s;
    notify();
}