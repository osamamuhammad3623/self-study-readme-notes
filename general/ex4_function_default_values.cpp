#include<iostream>
using namespace std;

/*
if a parameter has a default value,
then all the following parameters MUST have default values
*/

/* This func is wrong */
// void func(int x, int y=0, int z){
//     cout << x << " " << y << " " << z << "\n";
// }

/* Corrent version: */
void func(int x, int y=0, int z=-1){
    cout << x << " " << y << " " << z << "\n";
}

int main(){
    func(10); /* x is given a value, y & z are on the default */
    func(5,6); /* x & y are given values, z is on its default */
    func(1,2,3); /* x, y & z are given values */
}