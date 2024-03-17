#include <iostream>
#include <array>

int main(int argc, char* argv[])
{
    // standard C++ array
    int a[3] = {3, 4, 5};

    // STL array
    std::array<int, 5> arr = {3, 4, 5, 6, 7};

    /*
     * Element access
     */

    // access specified element
    std::cout << "Element index 2: " << arr[2] << std::endl;
    std::cout << "Element index 3: " << arr[3] << std::endl; // no bounds checking

    // access element with bounds checking
    std::cout << "Element index 2: " << arr.at(2) << std::endl;
    // std::cout << arr.at(3) << std::endl; // out of range error

    std::cout << "Element front: " << arr.front() << std::endl;
    std::cout << "Element back: " << arr.back() << std::endl;

    int* arr_ptr = arr.data();

    std::cout << "Dereferencing pointer: " << *arr_ptr << std::endl;
    arr_ptr++; // incrementing pointer address by one
    std::cout << "Dereferencing pointer: " << *arr_ptr << std::endl;

    /*
     * Iterators
     */

    // the member function `begin` returs a pointer to the beginning of the array
    std::cout << "Array begin address: " << arr.begin();
    std::cout << " dereferencing begin: " << *arr.begin() << std::endl;

    // the member function `end` returs a pointer to the pass-the-last element
    // of the array
    std::cout << "Array end address: " << arr.end() << std::endl;

    // sum 1 to each element of the array
    for (auto it  = arr.begin(); it != arr.end(); ++it) {
        // it is a pointer (memory address) to the begin of array
        std::cout << "In memory address: " << it;
        (*it)++;
        std::cout << " the value is: " << *it << std::endl;
    }

    // what if you only want to read the elements
    // in that case use cbegin() and cend()
    for (auto it  = arr.cbegin(); it != arr.cend(); ++it) {
        // (*it)++; // this is not allow
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // print elements in reverse order
    for (auto it = arr.crbegin(); it != arr.crend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    /*
     * Capacity
    */
    // check if the array is empty
    std::cout << arr.empty() << std::endl;
    // we can do it manually
    if (arr.begin() == arr.end()) {
        std::cout << "the array is empty" << std::endl;
    } else {
        std::cout << "the array is not empty" << std::endl;
    }

    // get the size of the array
    std::cout << "the size of the array: " << arr.size() << std::endl;

    // max number of element
    std::cout << "the MAX size of the array: " << arr.max_size() << std::endl;
    // remember array are fixed-size container, so max_size() is equal to size()
    
    /*
     * Non-member functions
    */
    std::cout << std::get<4>(arr) << std::endl; // this is evaluated a compile time
    // convert built-in array into std::array
    std::to_array(a); // c++ 20

    return 0;
}
