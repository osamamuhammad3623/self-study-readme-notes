#include <iostream>
#include <vector>
#include <string>
using namespace std;

void display_const_data ( const vector<string> *vec_ptr){
    // (*vec_ptr).at(0) = "hossam"; const data, you can't change it!
    for (string str : *vec_ptr){
        cout << str << "   ";
    }
    cout << "\n"; 
}

int main(){
    
    vector<string> names {"osama", "muhammad", "khaled", "abdalla"};
    display_const_data(&names);
}