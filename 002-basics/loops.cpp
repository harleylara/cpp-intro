#include <iostream>
#include <iterator> // required to get the `size` function

int main(int argc, char* argvp[])
{
    int numbers[] = {1, 2, 3, 4, 5, 6};

    std::cout << "\nwhile loop example 1" << std::endl;
    int couter = 0;
    while (couter < (sizeof(numbers)/sizeof(int))) {
        std::cout << numbers[couter] << std::endl;
        couter++;
    }

    // in C++ 17 you can use `size`, a convenient function
    // to get the size of an array
    std::cout << "\nwhile loop example 2" << std::endl;
    couter = 0; // just to reset the counter
    while (couter < std::size(numbers)) {
        std::cout << numbers[couter] << std::endl;
        couter++;
    }

    std::cout << "\nfor loop example 1" << std::endl;
    for (int i=0; i < std::size(numbers); i++) {
        std::cout << numbers[i] << std::endl;
    }

    // for-each like loop, was introduced in C++ 11
    std::cout << "\nfor loop example 2" << std::endl;
    for (const auto number : numbers) {
        std::cout << number << std::endl;
    }

    return 0;
}
