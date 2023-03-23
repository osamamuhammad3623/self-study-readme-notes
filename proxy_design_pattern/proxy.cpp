#include "proxy.h"

Proxy::Proxy(void){
    real_subject = new RealSubject;
}

bool Proxy::check_access(int some_number){
    // do any checks/filteration here
    bool result=false;
    if(some_number >= 10){
        result= true;
    }

    return result;
}

void Proxy::request_access(int some_number){
    if (check_access(some_number)){
        real_subject->request_access(some_number);
    }else{
        cout << "Access denied\n";
    }
}