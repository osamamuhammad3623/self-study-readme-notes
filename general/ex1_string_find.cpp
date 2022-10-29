#include<iostream>
using namespace std;

int main(void){
    string src = "are you serious?";
    string exists = "you";
    string not_exists = "no";

    /* if a substring is found, it returns first char index */
    cout << src.find(exists) << "\n";

    if(src.find(not_exists) == string::npos){
        cout << "not found\n";
    }
}