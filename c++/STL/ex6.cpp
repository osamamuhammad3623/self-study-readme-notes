#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void){

    /*
    all_of: returns true if all elements match a predicate!

    note: any_of returns true of at least one element matches the predicate
    */

    vector<int> nums {1,2,3,4,8,9,5};

    if (all_of(nums.begin(), nums.end(), [](int x) {return x <10;})){
        cout << "All elements are less than 10\n";
    }else{
        cout << "NOT all elements are less than 10\n";
    }

    if (all_of(nums.begin(), nums.end(), [](int x) {return x%3==0;})){
        cout << "At least one number is divisible by 3\n";
    }else{
        cout << "NOT all elements are divisible by 9\n";
    }    
}