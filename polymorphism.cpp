#include <iostream>
#include <memory>
#include <chrono>
#include <ranges>

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

    std::vector<std::unique_ptr<BaseClass>> raisers;
    raisers.reserve(operations_n);

    for (auto i : std::views::iota(0, operations_n)) {
        if (i % 10 == 0) {
            raisers.push_back(std::make_unique<Subclass>());
        } else {
            raisers.push_back(std::make_unique<BaseClass>());
        }
    }

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    long result = 0;
    for (const auto &current_raiser : raisers) {
        result = current_raiser->raise(result);
    }

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    std::cout << "Took " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << " ms\n";
    std::cout << "Result is " << result << std::endl;

    return 0;
}
