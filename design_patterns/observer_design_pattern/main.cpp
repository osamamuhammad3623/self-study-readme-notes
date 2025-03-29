#include <iostream>
#include "observer.h"
#include "subject.h"
using namespace std;

int main(void){
    SomeSubject master_subject;

    SomeObserver observer1("Observer 1");
    SomeObserver observer2("Observer 2");
    SomeObserver observer3("Observer 3");
    SomeObserver observer4("Observer 4");

    cout << "notify registered observers (currently 0)\n";
    master_subject.notify();

    // add some observers
    master_subject.register_observer(&observer1);
    master_subject.register_observer(&observer2);
    master_subject.register_observer(&observer3);

    cout << "3 observers are registered\n";
    cout << "changing subject state\n";
    master_subject.set_state("state s1");

    // add one more observer
    master_subject.register_observer(&observer4);
    cout << "Now 4 observers are registered\n";
    cout << "changing subject state\n";
    master_subject.set_state("state s2");
}