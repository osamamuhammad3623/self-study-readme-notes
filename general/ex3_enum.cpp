#include<iostream>
using namespace std;

enum {RED, YELLOW, GREEN}; // Works! [no name, no type]

enum : int8_t {STOP,READY,GO}; // Works! [no name but with identifying the data type]

enum Color {RED,YELLOW, GREEN};


int main(void){
    /* enums with no name provides no type safety,
        what if I want to make a variable that accepts only a color, not any integer! 
    */
    int random = RED;
    random = 5; 

    /* the solution is to give a name to the enum, this provides type safety */
    Color my_color = RED;
    //my_color = 2; Error! 
}