#include<iostream>
#include<filesystem>
using namespace std;

int main(void){
    filesystem::path test_path("D:\\");

    if (exists(test_path)){

        if(is_regular_file(test_path)){
            cout << "Path represents a file!\n";
        
        }else if (is_directory(test_path)){
            cout << "Path represents a directory!\n";
        }
    }else{
        cout << "Path doesn't exist!\n";
    }
}