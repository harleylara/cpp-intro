#include <iostream>
#include <string>
#include <cstdint>

struct vec3_t {
    float x, y, z;
};

class RobotBase
{
    std::string name_;
    uint8_t battery_; // battery level in percentage
public:
    vec3_t position{};

    RobotBase() : name_("robot_name"), battery_(0) {}

    RobotBase(std::string name): name_(name), battery_(0) {}
    RobotBase(std::string name, uint8_t battery): name_(name), battery_(battery) {}

    int getBattery() {
        return battery_;
    }

    std::string getName() {
        return name_;

    }
};

class Drone: public RobotBase
{
public:
    float barometer = 0.0; // extending class with more members
};

int main(int argc, char* argv[])
{

    RobotBase robile;
    std::cout << robile.getName() <<  "'s position in x " <<  robile.position.x << std::endl;
    std::cout << robile.getName() <<  "'s battery: " <<  robile.getBattery() << std::endl;

    // Since C++ 11 you can use agregate initialization
    // https://en.cppreference.com/w/cpp/language/aggregate_initialization
    // set data members to zero
    RobotBase robot {"freddy", 100};
    std::cout << robot.getName() << "'s position in x " <<  robot.position.x << std::endl;
    std::cout << robot.getName() << "'s battery: " << robot.getBattery() << std::endl;

    Drone drone;
    // the inheritance of the `RobotBase` class
    // allows us to inherit the position member in the `Drone` class
    std::cout << drone.getName() <<  "'s position in x " << drone.position.x << std::endl;
    std::cout << drone.getName() << "'s barometer value " << drone.barometer << std::endl;

    return 0;
}
