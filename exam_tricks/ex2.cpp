#include<iostream>
#include<string>

class Base { 

protected: 
    std::string name = "Base"; 
public: 
    std::string getName() { return name; }
}; 

class Child : public Base { 
protected: 
    std::string name = "Child"; 
}; 

int main() {
    Child c; 
    /* if the method is not found, it goes to higher classes to find it */
    /* if not found in the public class or its parents, that's an error! */
    std::cout << c.getName();

}