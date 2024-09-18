#include <iostream>
#include <string>

// this can reprents any 3 dimentional
// vector. For exmaple linear velocity in x, y and z
// Struct is a user definend data container.
struct simple_vec3_t {
    float x, y, z;
};

// C-style
typedef struct {
    float x, y, z, w;
} quaternion_t;

// With constructor
struct constructor_vec3_t {
    float x, y, z;

    constructor_vec3_t(float x, float y, float z) : x(x), y(y), z(z) {}
};

// with constructor and default parameters
struct vec3_t {
    float x, y, z;

    vec3_t() : x(0.0), y(0.0), z(0.0) {}

    vec3_t(float x, float y, float z) : x(x), y(y), z(z) {}

    void displayInfo() {
        std::cout << "x: " << x << ", y: " << y << ", z: " << z << std::endl;
    }
};

int main(int argc, char* argv[])
{
    simple_vec3_t vel1;

    vel1.x = 1;
    vel1.y = 0;
    vel1.z = 0;

    std::cout << "display information" << std::endl;
    std::cout << vel1.x << std::endl;
    std::cout << vel1.y << std::endl;
    std::cout << vel1.z << std::endl;

    std::cout << "\nwhat happens if we access the members before initialization?" << std::endl;
    simple_vec3_t vel2;
    std::cout << vel2.x << std::endl;
    std::cout << vel2.y << std::endl;
    std::cout << vel2.z << std::endl;

    std::cout << "\ncan we for the user to initialize the values?" << std::endl;
    constructor_vec3_t vel3(0,0,0);
    std::cout << vel3.x << std::endl;
    std::cout << vel3.y << std::endl;
    std::cout << vel3.z << std::endl;


    std::cout << "\ncan we make it more convenient?" << std::endl;
    vec3_t vel; // just declare your struct and dont worry
    // std::cout << vel.x << std::endl;
    // std::cout << vel.y << std::endl;
    // std::cout << vel.z << std::endl;
    vel.displayInfo();

    std::cout << "\nnesting structs" << std::endl;
    struct twist_t {
        vec3_t linear, angular;

        twist_t() : linear(0.0, 0.0, 0.0), angular(0.0, 0.0, 0.0) {}

        twist_t(vec3_t linear, vec3_t angular) : linear(linear), angular(angular) {}

        void displayInfo() {
            std::cout << "Linear:" << std::endl;;
            std::cout << "  "; // just to make it more readable
            std::cout << "x: " << linear.x << ", ";
            std::cout << "y: " << linear.y << ", ";
            std::cout << "z: " << linear.z << std::endl;
            std::cout << "Angular:" << std::endl;;
            std::cout << "  "; // just to make it more readable
            std::cout << "x: " << angular.x << ", ";
            std::cout << "y: " << angular.y << ", ";
            std::cout << "z: " << angular.z << std::endl;
        }
    };

    twist_t robot_twist(vec3_t(1.2, 3.5, 0), vec3_t(0.6, 1.1, 0));
    // twist robot_twist = {vec3_t(1.2, 3.5, 0), vec3_t(0.6, 1.1, 0)}; // this also works

    robot_twist.displayInfo();

    std::cout << "\ninheritance in struct" << std::endl;
    struct Robot : public twist_t {
        std::string name;

        Robot() : name("robot_name") {}

        Robot(std::string name) : name(name) {}

        void info() {
            std::cout << "Name: " << name << std::endl;
            displayInfo();
        }
    };

    Robot robile;

    robile.info();

    return  0;
}
