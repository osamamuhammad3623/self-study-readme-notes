#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void){
    vector<int> n {4,8,9,7,2,0,6,15};

    /*
    min_element and max_element return iterator to min/max elements in containers
    */
    
    cout << "Min element is " << *min_element(n.begin(), n.end()) << "\n";
    cout << "Max element is " << *max_element(n.begin(), n.end()) << "\n";
}