#include<iostream>
using namespace std;

/*
Simple example of templates
*/

// this function will be executed as long as T supports '>' operator
template <typename T>
T compare(T a, T b){
    return (a > b) ? a : b;
}


// we can define more than one template
template <typename T1, typename T2>
void display(T1 a, T2 b){
    cout << a << " " << b << "\n";
}



int main(void){
    cout << compare<int>(5,14) << "\n";
    cout << compare<float>(5.4,1.4) << "\n";
    cout << compare<char>('A','B') << "\n";

    display<int,int>(15,20);
    display<char,int>('A',20);
    display<int,string>(15,"Osama");
    display<bool,char>(1,'C');
}