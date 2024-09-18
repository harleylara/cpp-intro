#include <iostream>
#include <cstdint>

// Enum to represent different types of actuators
enum ActuatorType {
    MOTOR,
    SERVO,
    STEPPER

};

enum SensorType {
    CAMERA = 5,
    LIDAR
};

// Union to hold different actuator data
union ActuatorData {
    float speed;      // for MOTOR
    float angle;    // for SERVO
    int steps;      // for STEPPER
};

// Struct representing an actuator command
struct ActuatorCommand {
    ActuatorType type;
    ActuatorData data;
};

// Function to execute actuator commands
void executeActuatorCommand(const ActuatorCommand& command) {
    switch (command.type) {
        case MOTOR:
            std::cout << "Setting motor speed to: " << command.data.speed << std::endl;
            // Execute motor command here
            break;
        case SERVO:

            std::cout << "Setting servo angle to: " << command.data.angle << " degrees" << std::endl;
            // Execute servo command here
            break;
        case STEPPER:
            std::cout << "Moving stepper motor " << command.data.steps << " steps" << std::endl;
            // Execute stepper command here
            break;
        default:

            std::cout << "Unknown actuator type" << std::endl;
            break;
    }
}

int main(int argc, char* argv[])
{
    // define an type alias
    typedef int my_int;
    // this is just a normal integer
    my_int level = 70;

    using battery = uint8_t;
    battery var = 23;
    // Note that neither typedef nor using create new distinct data types. They only create synonyms of existing types.

    std::cout << "MOTOR is option: " << MOTOR << std::endl;
    std::cout << "SERVO is option: " << SERVO << std::endl;
    std::cout << "STEPPER is option: " << STEPPER << std::endl;

    std::cout << "LIDAR is option: " << LIDAR << std::endl;

    // Example usage
    ActuatorCommand motorCommand;
    motorCommand.type = MOTOR;
    motorCommand.data.speed = 2.3;

    ActuatorCommand servoCommand = {SERVO, {.angle = 1.43}};

    ActuatorCommand stepperCommand = {STEPPER, {.steps = 200}}; // Move stepper motor 200 steps

    // Execute commands
    executeActuatorCommand(motorCommand);
    executeActuatorCommand(servoCommand);
    executeActuatorCommand(stepperCommand);

    return 0;
}
