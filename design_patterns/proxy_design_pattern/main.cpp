#include <iostream>
#include "proxy.h"
using namespace std;

int main(void){

    Proxy custom_firewall;

    cout << "Trying to request for access using a wrong less than 10\n";
    custom_firewall.request_access(5);

    cout << "Trying to request for access using a valid number\n";
    custom_firewall.request_access(15);
}