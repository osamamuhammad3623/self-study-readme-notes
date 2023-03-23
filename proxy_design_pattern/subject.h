#ifndef SUBJECT
#define SUBJECT

#include <iostream>
using namespace std;

class Subject{
public:
    virtual void request_access(int some_number) =0;
};

#endif