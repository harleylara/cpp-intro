#include <iostream>
#include <string> // to use string class

void print(const std::string message)
{
    std::cout << message << std::endl;
}

// passing arguments "by value"
int sum_by_value(int a, int b)
{
    return a + b;
}

template <class T>
T sum(T a,T b)
{
    return a+b;
}

// passing arguments "by reference"
double get_acc(double &delta_vel, double &delta_t)
{
    return delta_vel/delta_t;
}

template <class T, int N>
T times(T a)
{
    return a*N;
}

// return a const reference to the max value
const int& getMax(const int& a, const int& b) {
    return (a > b) ? a : b;
}

int main(int argc, char* argv[])
{
    print("Python is cool");

    int a = 6;
    int b = 2;
    std::cout << "sum return " << sum_by_value(a, b) << std::endl;

    double delta_vel = 0.3;
    double delta_t = 1.2;

    std::cout << get_acc(delta_vel, delta_t) << std::endl;

    int x = 5, y = 10;
    const int& maxVal = getMax(x, y);
    std::cout << "Max value: " << maxVal << std::endl;
    // if you change "y" (in the case the max value)
    y = 30;
    // maxVal also change
    std::cout << "Max value: " << maxVal << std::endl;

    std::cout << sum<int>(1, 2) << std::endl;
    // or just
    std::cout << sum(1, 2) << std::endl;
    std::cout << sum<float>(2.3, 3.7) << std::endl;
    std::cout << sum(2.0, 3.7) << std::endl;

    // templates can also include expressions
    // multiply 2, 3 times
    std::cout << times<int, 3>(2) << std::endl;

    return 0;
}
