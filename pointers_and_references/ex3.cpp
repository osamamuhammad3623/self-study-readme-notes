#include <iostream>
using namespace std;

int main(){
    int *ptr{nullptr};
    ptr = new int; // allocate int on the heap
    *ptr = 15;

    cout << "Value = " << *ptr << " on address: " << ptr << "\n";

    delete ptr; // deallocate memory

    cout << "Data is freed from the heap \n";
    cout << "Current [garbage] data on that address: " << *ptr << "\n";
}