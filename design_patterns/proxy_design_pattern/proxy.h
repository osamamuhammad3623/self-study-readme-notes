#ifndef PROXY
#define PROXY

#include "subject.h"
#include "real_subject.h"

class Proxy :public Subject{
private:
    RealSubject* real_subject;
    bool check_access(int some_number);

public:
    void request_access(int some_number);
    Proxy(void);
};

#endif