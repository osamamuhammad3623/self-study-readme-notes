#include<iostream>
#include<functional>
using namespace std;

void say_my_name(void){
    cout << "Osama\n";
}

class Test{
public:
    void print_number(int n){
        cout << n << "\n";
    }

    static void print_char(char c){
        cout << c << "\n";
    }
};

int main(void){
    /* invoke can call a function */
    invoke(say_my_name);
    
    /* invoke can use a function pointer to call a function */
    void (*say_my_name_ptr)(void) = say_my_name;
    invoke(say_my_name_ptr);

    /* invoke can call a member method */
    Test t;
    invoke(Test::print_number, t, 5);
    
    /* for a static member method, do NOT specify the object you operate on */
    invoke(Test::print_char, 'X');
}