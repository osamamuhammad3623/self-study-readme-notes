#include<iostream>
using namespace std;

int globalVarX = 10;

void func(int *ptr) {
    ptr = &globalVarX;
    cout<< "In function, after assigning " << ptr <<"\n";
}

int main() {

    int *ptr = nullptr;

    cout<< "Before calling function " << ptr <<"\n";

    func(ptr);

    cout<< "After calling function " << ptr <<"\n";
}