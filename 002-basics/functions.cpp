#include <iostream>

double get_acc(double delta_vel, double delta_t)
{
    return delta_vel/delta_t;
}

int main(int argc, char* argv[])
{
    std::cout << get_acc(0.3, 1.2) << std::endl;

    return 0;
}
