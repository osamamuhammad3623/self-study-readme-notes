#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void){
    
    /*
    countif: used to find number of occurences of elements based on a lambda expression [predicate]
    */

    vector<int> n {1,58,23,97,8,954,48,4,84,64,14,598,9,56};

    int even_elem = count_if(n.begin(), n.end(), [](int x) {return x%2==0;});
    int odd_elem = count_if(n.begin(), n.end(), [](int x) {return x%2==1;});
    cout << even_elem << " even elements are found!\n";
    cout << "and " << odd_elem << " odd numbers \n";
}