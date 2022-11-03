#include<string>

int main(void){
    /* Does this code compile? */

    std::string(name); // this is just declaration, same as std::string name;

    {
        std::string(name); // another declaration in an inner scope
    }
}