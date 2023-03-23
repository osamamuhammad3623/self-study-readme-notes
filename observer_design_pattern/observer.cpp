#include "observer.h"

/****************************
SomeObserver implementation
****************************/ 
void SomeObserver::update(void){
    cout << name << ": I saw you!\n";
}

SomeObserver::SomeObserver(string _name) :name{_name}{

}
