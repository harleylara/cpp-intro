#include <iostream>
#include <string>

// Simulated motor driver API (C-style functions)
bool motor_driver_connect(int motor_id) {
    std::cout << "Motor " << motor_id << " connected\n";
    return true;
}
void motor_driver_disconnect(int motor_id) {
    std::cout << "Motor " << motor_id << " disconnected\n";
}
void motor_driver_set_speed(int motor_id, float speed) {
    std::cout << "Motor " << motor_id << " speed set to " << speed << "\n";
}

// RAII wrapper for a motor resource
class Motor {
    int id;
    bool connected;

public:
    explicit Motor(int motor_id) : id(motor_id), connected(false) {
        if (motor_driver_connect(id)) {
            connected = true;
        } else {
            throw std::runtime_error("Failed to connect motor " + std::to_string(id));
        }
    }

    // Non-copyable (each motor resource is unique)
    Motor(const Motor&) = delete;
    Motor& operator=(const Motor&) = delete;

    // Allow moving
    Motor(Motor&& other) noexcept : id(other.id), connected(other.connected) {
        other.connected = false;
    }

    // RAII: safely release resource
    ~Motor() {
        if (connected) {
            motor_driver_disconnect(id);
        }
    }

    // Control method
    void set_speed(float speed) {
        if (!connected) throw std::runtime_error("Motor not connected");
        motor_driver_set_speed(id, speed);
    }
};

int main() {
    try {
        Motor left_wheel(1);
        Motor right_wheel(2);

        left_wheel.set_speed(0.5f);
        right_wheel.set_speed(0.5f);

        // When main exits, both motors are automatically disconnected
    }
    catch (const std::exception& e) {
        std::cerr << "Robot error: " << e.what() << "\n";
    }
}

