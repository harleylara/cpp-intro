#include <iostream>
#include <chrono>

int main(int argc, char* argv[])
{
    std::cout << std::chrono::system_clock::now() << std::endl;
    return 0;
}
