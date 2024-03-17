#include <iostream>
#include <vector>

int main(int argc, char* argv[]){

    // set the default size to zero
    std::vector<int> vec;
    vec.push_back(4);
    vec.push_back(1);
    vec.push_back(3);

    // accessing elements
    std::cout << vec[2] << std::endl; // (no range check)
    std::cout << vec.at(2) << std::endl; // (throw range_error exception)

    for (int i; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    for (std::vector<int>::iterator itr = vec.begin(); itr != vec.end(); ++itr) {
        std::cout << *itr << " ";
    }
    std::cout << std::endl;

    for (auto it: vec) { // C++ 11
        std::cout << it << " ";
    }
    std::cout << std::endl;


    return 0;
}
