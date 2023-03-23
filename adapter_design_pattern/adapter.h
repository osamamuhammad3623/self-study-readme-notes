#ifndef ADAPTER
#define ADAPTER

#include <iostream>
#include "old_interface.h"
#include "new_interface.h"
using namespace std;

class OldInterfaceAdapter : NewInterface{
private:
    OldInterface* old_interface;
public:
    void method1(void);
    void method2(void);
};

#endif