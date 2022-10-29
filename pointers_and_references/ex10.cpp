#include<iostream>
using namespace std;

int main(void){
    int variable = 10; /* a variable */
    int &ref_to_var = variable; /* a reference to the variable */

    ref_to_var = 15; /* changing the reference, changes the actual variable */
    cout << variable << "\n";
}