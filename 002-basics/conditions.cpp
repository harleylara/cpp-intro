#include <iostream>

int main(int argc, char* argv[])
{
    int x = 20;
    int y = 25;

    if (x == 20) std::cout << "x is EQUAL to 20" << std::endl;

    // more commonly formatted
    if (x == 20)
        std::cout << "x is EQUAL to 20" << std::endl;

    // you can use curly braces for define the section
    if (x > 0)
    {
        std::cout << "x is GREATHER-THAN" << std::endl;
    }
    else if (x < 0)
    {
        std::cout << "x is LESS-THAN" << std::endl;
    }
    else {
        std::cout << "x is 0" << std::endl;
    }

    if (x > 0 && y > 0)
        std::cout << "both, x AND y are positive" << std::endl;

    if (x > 0 || y > 0)
        std::cout << "either x OR y is positive" << std::endl;

    switch (x) {
        case 1:
            std::cout << "x is 1" << std::endl;
            break;
        case 2:
            std::cout << "x is 2" << std::endl;
            break;
        case 3:
            std::cout << "x is 3" << std::endl;
            break;
        default:
            std::cout << "x is " << x << std::endl;
            break;
    }

    return 0;
}
