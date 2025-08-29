// g++ -O2 f.51.cpp -o f.51
#include <string>
#include <iostream>

void configure_robot(float battery_capacity, int wheel_count, bool autonomous = false) {
    std::cout << "Configuring robot with " << wheel_count << " wheels, ";
    std::cout << (autonomous ? "autonomous mode enabled\n" : "manual mode only\n");
}

void configure_robot(float battery_capacity, int wheel_count, std::string const& robot_name) {
    std::cout << "Configuring robot '" << robot_name 
              << "' with " << wheel_count << " wheels\n";
}

int main() {
    configure_robot(85.0, 4, "RobileRobot");
    return 0;
}

// Note: This example illustrates CG "F.51 Where there is a choice, prefer default arguments over overloading"
