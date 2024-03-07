#include <iostream>

int main(int argc, char* argv[])
{
    // 1. Direct-initialization
    // stack memory allocation
    int foo;
    // garbage value
    std::cout << "The content of foo is: " << foo << std::endl;

    // 2. Copy-initialization
    // c-like initialization
    int bar = 1;
    std::cout << "The content of bar is: " << bar << std::endl;
    int var = (((29))); // just to make the point
    // in this context the parenthesis is an "expression" and when the expression is evaluated the result is still 29.
    std::cout << "The content of var is: " << var << std::endl;

    // 3. Aggregate initialization. 
    // List-initialization syntax. (since C++11)
    int foobar = {2};
    std::cout << "The content of foobar is: " << foobar << std::endl;

    // 4. Direct-initialization
    int b(7);
    std::cout << "The content of b is: " << b << std::endl;

    int c(); // this is a function declaration NOT a variable declaration
    int d{2}; // Direct-initialization using List-initialization syntax (since C++11)

    return 0;
}
