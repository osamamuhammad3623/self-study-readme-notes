#include <iostream>
class A
{
private:
    int x;
public:
    A(int _x)  {  x = _x; }
    int get()  { return x; }
};
 
class B
{
    static A a;
public:
    static int get()  { return a.get();  }
};


/* creating the static variable that's in class B, and once it's created, it's always there [static]
so all other objects of class B will use this variable and will not create another one!
*/
A B::a = A(10);

int main(void)
{
    B b;
    std::cout << b.get();
    return 0;
}