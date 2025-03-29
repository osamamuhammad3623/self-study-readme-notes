#include<iostream>
#include<vector>
using namespace std;

/*
Example of class templates 
*/

template <typename T>
class Test{
public:
    T value;

    Test(T v) : value{v}{}

    T get_value(){
        return value;
    }
};

int main(void){
    Test<int> t1{5};
    Test<string> t2{"Osama"};
    Test<char> t3{'A'};
    Test<double> t4{3.14};

    cout << t1.get_value() << "\n";
    cout << t2.get_value() << "\n";
    cout << t3.get_value() << "\n";
    cout << t4.get_value() << "\n";
}