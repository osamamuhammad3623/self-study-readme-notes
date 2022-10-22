#include<iostream>
#include<any>
using namespace std;

int main(void){

    auto my_variable = any(35);
    cout << any_cast<int>(my_variable) << "\n";
    // cout << any_cast<string>(my_variable) --> throws an error

    my_variable = "osama"s;
    cout << any_cast<string>(my_variable) << "\n";

    try{
        cout << any_cast<int>(my_variable) << "\n";
    
    }catch(const bad_any_cast &e){
        cout << "My variable is NOT an int anymore\n";
    }
}