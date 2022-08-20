#include<iostream>
#include<vector>
using namespace std;

int main(void){

    vector<string> names = {"osama", "muhammad", "khaled"};

    for (string s: names){
        s = "XYZ";
    }

    for (string s: names){
        cout << s << "\n";
    }

    /*
    in the first for loop, you changed the COPY of the element, not the actual element
    */


    /* in the following for loop, you referencd each element in the vector,
    so changing the ref. means you change the actual element */
    for (string &s: names){
        s = "XYZ";
    }

    for (string s: names){
        cout << s << "\n";
    }

    /* to prevent changing the actual elements, use const */
    for (string const &str: names){
        // str= "xyz"; Error!
    }
}