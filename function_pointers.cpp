#include <iostream>
#include <memory>
#include <ranges>
#include "timer.cpp"


long raise_by_one(long number) {
    return number + 1;
}

long raise_by_two(long number) {
    return number + 2;
}


int main(int argc, char *argv[]) {
    int operations_n = std::stoi(argv[1]);

    Timer timer;

    using RaiserFunction = long(long);

    std::vector<RaiserFunction *> raisers;
    raisers.reserve(operations_n);

    for (auto i : std::views::iota(0, operations_n)) {
        raisers.push_back(i % 10 == 0 ? raise_by_two : raise_by_one);
    }

    int initialization_time_ms = timer.ms_elapsed();
    timer.reset();

    long result = 0;
    for (const auto &current_raiser : raisers) {
        result = current_raiser(result);
    }

    int execution_time_ms = timer.ms_elapsed();

    std::cout << "Initialization time = " << initialization_time_ms << " ms\n";
    std::cout << "Execution time      = " << execution_time_ms << " ms\n";
    std::cout << "Result              = " << result << std::endl;

    return 0;
}
