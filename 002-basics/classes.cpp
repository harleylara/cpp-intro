#include <iostream>
#include <string>
#include <cstdint>

struct vec3_t {
    float x, y, z;
};

class SimpleRobot
{
    std::string name_;
    uint8_t battery_; // battery level in percentage
public:
    // vec3_t position;
    vec3_t position{}; // possible fix


    int getBattery() {
        return battery_;
    }

    std::string getName() {
        return name_;
    }

    void setName(std::string name) {
        name_ = name;
    }
};

class BetterRobot
{
    std::string name_;
    uint8_t battery_;
public:
    vec3_t position{};

    BetterRobot() : name_("robot_name"), battery_(0) {}

    // BetterRobot(std::string name): name_(name) {}
    BetterRobot(std::string name): name_(name), battery_(0) {}

    BetterRobot(std::string name, uint8_t battery): name_(name), battery_(battery) {}

    int getBattery() {
        return battery_;
    }

    std::string getName() {
        return name_;
    }

    void setName(std::string name) {
        name_ = name;
    }

    // void info() {
    //     std::cout << "\nName: " << name_ << std::endl;
    //     std::cout << "Battery: " << unsigned(battery_) << std::endl;
    //     std::cout << std::endl;
    // }
    void info();

};

// using the scope operator for extending the class
// with the implementation of a member function
void BetterRobot::info() {
    std::cout << "\nName: " << name_ << std::endl;
    std::cout << "Battery: " << unsigned(battery_) << std::endl;
    std::cout << std::endl;
}

int main(int argc, char* argv[])
{

    SimpleRobot robot;

    // ## Members initialization ##

    // what is the initial value of the position on x?
    // [FIX] initialize the position to zero
    std::cout << "position in x: " << robot.position.x << std::endl;

    // how to access a private member outside the class ?
    // std::cout << "Name: " << robot.name_ << std::endl; // this is private
    // [FIX] getter interface to read a private member
    std::cout << "Name: " << robot.getName() << std::endl; // empty right?

    // how to set a private member?
    // robot.name_ =  "robile";
    // robot.name =  "robile";
    robot.setName("robile");
    std::cout << "Name: " << robot.getName() << std::endl;

    // can we initialize members with **default values**
    // during object instantiation?
    BetterRobot quadruped;
    // [FIX] default initialization
    quadruped.info();

    // [FIX] what if we want to pass the name as argument during instantiation?
    BetterRobot other_quadruped("nala");
    std::cout << "Name: " << other_quadruped.getName() << ", Battery: " << other_quadruped.getBattery() << std::endl;
    // [FIX] add a member function to print the information
    other_quadruped.info();

    // [FIX] what if I want to initialize name and battery ?
    BetterRobot one_more_quadruped("nala", 100);
    one_more_quadruped.info();

    // using uniform initialization
    BetterRobot its_the_last_one_i_promise = {"nala", 100};
    its_the_last_one_i_promise.info();

    return 0;
}
