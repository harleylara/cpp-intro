#include <iostream>
#include <string> // to use string class

void print(std::string message)
{
    std::cout << message << std::endl;
}

double get_acc(double delta_vel, double delta_t)
{
    return delta_vel/delta_t;
}


int main(int argc, char* argv[])
{
    print("Python is cool");

    std::cout << get_acc(0.3, 1.2) << std::endl;

    return 0;
}
