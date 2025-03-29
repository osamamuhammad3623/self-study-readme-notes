#include<iostream>
#include<string>

class A {
	int* ptr;

public:
	A (int num) { ptr = new int(num);  }
	void setNum(int num) { *ptr = num; }
	int getNum()  {  return *ptr;  }

};

int main() {
	A a(5);
	/* creates 'b' using the default copy constructor, 
	resulting in a and b sharing the same dynamically allocated memory.
	*/
	A b(a); 
	b.setNum(10); // updates the shared memory to 10.

	std::cout << a.getNum()<< ", " << b.getNum()<< "\n";

}