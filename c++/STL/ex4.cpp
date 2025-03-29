#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void){
    /* count: returns number of occurences of an element */

    vector<string> names {"osama", "mahmoud", "khaled", "abdelrahman", "mahmoud"};
    int counter = count(names.begin(), names.end(), "mahmoud");
    
    cout << "Mahmoud was found " << counter << " times\n";
    cout << "and Osama was found " << count(names.begin(), names.end(), "osama") << " time\n";

}