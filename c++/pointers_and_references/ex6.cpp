#include <iostream>
using namespace std;

int main(){
    int a{100};
    int b {50};

    /***** pointer to const *****/
    /* Location changes, value doesn't */
    const int *ptr;
    ptr = &a;

    cout << *ptr << "\n";
    ptr = &b;
    cout << *ptr << "\n";
    /* *ptr = 15; Error! */


    /***** const pointer *****/
    /* Value changes, location doesn't */
    int * const cptr{&a}; // must be initialized
    cout << *cptr << "\n";
    *cptr = 150;
    cout << *cptr << "\n";
    /* cptr = &b; Error! */


    /***** const pointer to const *****/
    /* You can change nothing :) */
    int const * const all_const_ptr {&a};
    cout << *all_const_ptr << "\n";
    /* all_const_ptr = &b; Error! */
    /* *all_const_ptr = 120; Error! */

}