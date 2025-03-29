#ifndef REALSUBJECT
#define REALSUBJECT

#include "subject.h"

class RealSubject :public Subject{
public:
    void request_access(int some_number);
};

#endif