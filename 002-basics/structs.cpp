#include <iostream>

int main(int argc, char* argv[])
{

    struct linear_vel_t {
        double x;
        double y;
        double z;
    };

    linear_vel_t robot_vel;

    robot_vel.x = 1;
    robot_vel.y = 0;
    robot_vel.z = 0;

    std::cout << robot_vel.x << std::endl;
    std::cout << robot_vel.y << std::endl;
    std::cout << robot_vel.z << std::endl;

    return  0;
}
