#include <iostream>
#include <string>
#include <vector>
#include <chrono>

class RobotBad {
    std::string name;
    int wheel_count;
    float battery_level;
public:
    RobotBad() : name("Unnamed"), wheel_count(4), battery_level(100.0f) {}
};

class RobotGood {
    std::string name = "Unnamed";
    int wheel_count = 4;
    float battery_level = 100.0f;
};

template <typename Robot>
void benchmark(const std::string& label) {
    constexpr int N = 10'000'000;
    auto start = std::chrono::high_resolution_clock::now();
    std::vector<Robot> robots;
    robots.reserve(N);
    for (int i = 0; i < N; ++i) {
        robots.emplace_back();
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << label << " construction time: " << diff.count() << " s\n";
}

int main() {
    benchmark<RobotBad>("RobotBad");
    benchmark<RobotGood>("RobotGood");
}
