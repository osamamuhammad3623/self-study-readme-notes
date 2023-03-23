#include "adapter.h"

void OldInterfaceAdapter::method1(void){
    cout << "Connecting New Interface to Old Interface\n";
    old_interface->approach1();
}

void OldInterfaceAdapter::method2(void){
    cout << "Connecting New Interface to Old Interface\n";
    old_interface->approach2();
}