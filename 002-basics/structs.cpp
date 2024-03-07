#include <iostream>

// this can reprents any 3 dimentional
// vector. For exmaple linear velocity in x, y and z
// Struct is a user definend data container.
struct vec3_t {
    float x, y, z;
};

int main(int argc, char* argv[])
{
    vec3_t vel;

    vel.x = 1;
    vel.y = 0;
    vel.z = 0;

    std::cout << vel.x << std::endl;
    std::cout << vel.y << std::endl;
    std::cout << vel.z << std::endl;

    struct twist {
        vec3_t linear, angular;
    };

    twist robot_twist;

    robot_twist.linear.x = 1.2;
    robot_twist.linear.y = 3.5;
    robot_twist.linear.z = 0;
    robot_twist.angular.x = 0.6;
    robot_twist.angular.y = 1.1;
    robot_twist.angular.z = 0;

    std::cout << "Robot twist information" << std::endl;
    std::cout << robot_twist.linear.x << std::endl;
    std::cout << robot_twist.linear.y << std::endl;
    std::cout << robot_twist.linear.z << std::endl;
    std::cout << robot_twist.angular.x << std::endl;
    std::cout << robot_twist.angular.y << std::endl;
    std::cout << robot_twist.angular.z << std::endl;


    return  0;
}
