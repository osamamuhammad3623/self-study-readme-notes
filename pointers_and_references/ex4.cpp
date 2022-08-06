#include <iostream>
using namespace std;

int main(){

    cout << "Size of array to be allocated: ";
    int input_size; cin >> input_size;

    int *array{nullptr};
    array  = new int[input_size];

    cout << (sizeof array)*input_size << " bytes have been allocated on the heap";

    // get array values using array name pointer
    for (int i=0; i< input_size; i++){
        cout << "\nValue of " << i << "th element = ";
        cin >> *(array+i);
    }

    cout << "\n\n";

    for (int i=0; i< input_size; i++){
        cout << i << "th element = " << *(array+i) << "\n";
    }

    delete [] array;

    cout << "Array is freed from the heap, new [garbage] values are:\n";
    for (int i=0; i< input_size; i++){
        cout << i << "th element = " << *(array+i) << "\n";
    }

    /* garbage values may be the same values of the array, it up to the system.
    you deleted a block of memory meaning that you are promising not to use that pointer again,
    The system is thus free to do what it wants with that memory,
    It may re-use it, It may do nothing with it initially.*/
}
