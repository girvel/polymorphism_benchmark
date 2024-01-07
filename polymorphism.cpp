#include <iostream>
#include <memory>
#include <ranges>
#include "time_point.cpp"

class BaseClass {
public:
    virtual long raise(long number) {
        return number + 1;
    }
};

class Subclass : public BaseClass {
public:
    long raise(long number) override {
        return number + 2;
    }
};

int main(int argc, char *argv[]) {
    int operations_n = std::stoi(argv[1]);

    TimePoint timer;

    std::vector<std::unique_ptr<BaseClass>> raisers;
    raisers.reserve(operations_n);

    for (auto i : std::views::iota(0, operations_n)) {
        if (i % 10 == 0) {
            raisers.push_back(std::make_unique<Subclass>());
        } else {
            raisers.push_back(std::make_unique<BaseClass>());
        }
    }

    int initialization_time_ms = timer.ms_elapsed();
    timer.reset();

    long result = 0;
    for (const auto &current_raiser : raisers) {
        result = current_raiser->raise(result);
    }

    int execution_time_ms = timer.ms_elapsed();

    std::cout << "Initialization time = " << initialization_time_ms << " ms\n";
    std::cout << "Execution time      = " << execution_time_ms << " ms\n";
    std::cout << "Result              = " << result << std::endl;

    return 0;
}
