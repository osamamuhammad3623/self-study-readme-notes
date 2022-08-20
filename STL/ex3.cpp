#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void){

    /*
    find: if element is found (first occurence), return an iterator pointing to it,
        otherwise return an iterator pointing to the end
    */

    /*
    if find is used with user-defined classes, operator== MUST BE provided by user class 
    */

    vector<int> v {1,5,13,54,38,43,84,38,47};
    auto it = find(v.begin(), v.end(), 35);
    if (it == v.end()){
        cout << "Not found\n"; 
    }else{
        cout << *it << " is found\n";
    }

    it = find(v.begin(), v.end(), 43);
    if (it == v.end()){
        cout << "Not found\n"; 
    }else{
        cout << *it << " is found\n";
    }
}