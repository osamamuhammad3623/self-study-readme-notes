#include "old_interface.h"
#include "new_interface.h"
#include "adapter.h"

int main(void){
    OldInterface old_interface_obj;

    OldInterfaceAdapter adapter;

    cout << "Calling method1 [NewInterface] using the adapter\n";
    adapter.method1();
    cout << "******************\n";
    cout << "Calling method2 [NewInterface] using the adapter\n";
    adapter.method2();
}