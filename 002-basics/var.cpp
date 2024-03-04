#include <iostream>

int main(int argc, char* argv[])
{
    int foo;        // this is declaration
    int bar = 1;    // this is initialization

    // Three ways to initialize variables
    int a=5;    // c-like initialization
    int b(3);   // constructor initialization
    int c{2};   // uniform initialization

    auto result = a + b + c; // type deduction

    std::cout << result << std::endl;

    return 0;
}
