#include <iostream>
using namespace std;

int main(){

	int a = 10;
	char b = 'x';
	int *ptr = &a;
	char *cptr = &b;

	cout << sizeof a << "\n";
	cout << sizeof b << "\n";
	cout << sizeof ptr << "\n";
	cout << sizeof cptr << "\n";

	// all pointers have the same size, because they just hold a memory address
}
