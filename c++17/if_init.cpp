#include<iostream>
using namespace std;

uint8_t some_function(void){
    return 5;
}

int main(void){

    /*
    - a feature enabling initializing a variable that is only LOCAL 
        to the IF STATEMENT only (and else block)

    - if (init; condition){ ... }
    */
    if(int result = some_function(); result<0){
        cout << "Done!\n";
    }else{
        cout << "Not done!\nResult is: " << result;
    }

    //cout << result; result is NOT defined!
}