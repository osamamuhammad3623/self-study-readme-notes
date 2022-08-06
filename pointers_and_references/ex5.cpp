#include <iostream>
using namespace std;

int main(){

    cout << "Size of array to be allocated: ";
    int input_size; cin >> input_size;

    int *array{nullptr};
    array  = new int[input_size];

    for (int i=0; i< input_size; i++){
        *(array+i) = i;
    }

    char dir;
    int *current_ptr = array;
    // playing with the elements using a moving pointer
    while (cin >> dir){
    	if (dir == 'a'){
    		current_ptr--;
    	}else if (dir == 'd'){
    		current_ptr++;
    	}

    	cout << "Pointing to " << *current_ptr << "\n";
    }
}
