#include <iostream>
using namespace std;

/* A function that creates a dynamically-allocated array on the heap,
    and returns address of first element
*/

/*
    Returning a pointer to a local variable will give a Segmentation fault
    because the variable is no longer in stack.

    But, returning a pointer to dynamically-allocated memory works!
    because it's allocated on the heap, meaning that
    memeory is not deallocated/deleted when returning from the function
*/
int * create_int_array(int size, int init_val=0){
    int *array{nullptr};
    array = new int[size];
    // set init val
    for (int i=0; i< size;i++){
        *(array +i) = init_val;
    }

    return array;
}

/* this function returns a pointer to a local variable */
int * dump(){
    int s=15;
    return &s;
}

int main(){
    int *scores;
    int size=10;

    scores = create_int_array(size, 100);

    for (int i{}; i<size;i++){
        cout << *(scores+i) << " ";
    }

    scores = dump();
    // cout << *scores << "\n"; Error! 
}