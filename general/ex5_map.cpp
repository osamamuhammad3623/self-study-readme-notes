#include<iostream>
#include<map>
using namespace std;

int main(void){

    map<string, int> people;
    people["osama"] = 22;
    cout << people.size() << "\n";
    /* try to print a key that doesn't exist! */
    /* and watch the map size! */
    cout << people["mahmoud"] << "\n";
    cout << people.size();

    /*
    if you index a key that does NOT exist,
    C++ actually creates that key with value 0
    */
}