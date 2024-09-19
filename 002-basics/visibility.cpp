#include <iostream>

int a = 3;
int global_var;

namespace python {
    int a = 6;

    void print(std::string message) {
        std::cout << message << std::endl;
    }
}

namespace name1 {
    namespace name2 {
     int c = 4;
    }
    int c = name2::c;
}



int main(int argc, char* argv[]) {

    // difference between global and local scope
    std::cout << "global scope: " << a << std::endl;
    int b = 29;
    {
        int a = 5;
        std::cout << "local scope: " << a << std::endl;
        std::cout << "value of b: " << b << std::endl;
    }

    // grouping varibles, functions and more...
    python::print("Hello python");

    // what if I don't want to write `python`
    // every time I want to print a message?
    {
        using namespace python;
        {
            print("Testing python");
        }
    }
    // the keyword `using` introduces a name into the current scope
    // print("What's up with this?")

    // rename the namespace?
    namespace my_func = python;
    my_func::print("Renaming functions is fun...");
    python::print("but I can still use the previous namespace name");

    std::cout << name1::c << std::endl;

    // scope and storage
    int local_var;
    std::cout << "The value of global: " << global_var << std::endl;
    std::cout << "The value of local: " << local_var << std::endl;
    // Variables with **static storage** (such as global variables) that are not explicitly initialized are automatically initialized to zeroes.
    // Variables with **automatic storage** (such as local variables) that are not explicitly initialized are left uninitialized, and thus have an undetermined value.

    return 0;
}
