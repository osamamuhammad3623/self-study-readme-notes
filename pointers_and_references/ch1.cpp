#include <iostream>
using namespace std;

/*
Write a C++ function that expects two arrays of integers and their size [same size]
and dynamically allocates a new array of integers whose elements
are the sum of the elements of the 2 arrays (at same index)

The function should return a pointer to the newly allocated array. 
*/

int * sum_two_arrays(const int *array1, const int* array2, int size){
    int *result = new int[size];
    for (int i=0; i< size;i++){
        *(result+i) = *(array1+i) + *(array2+i);
    }

    return result;
}

int main(void){
    int arr1[5] = {5,14,3,8 ,9};
    int arr2[5] = {6,1 ,2,10,9};

    int *result = sum_two_arrays(arr1, arr2, 5);

    for (int i=0; i< 5; i++){
        cout << *(result+i) << "\n";
    }
}