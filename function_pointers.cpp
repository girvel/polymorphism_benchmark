#include <iostream>
#include <memory>
#include <chrono>
#include <ranges>


long raise_by_one(long number) {
    return number + 1;
}

long raise_by_two(long number) {
    return number + 2;
}


int main(int argc, char *argv[]) {
    int operations_n = std::stoi(argv[1]);

    using RaiserFunction = long(long);

    std::vector<RaiserFunction *> raisers;
    raisers.reserve(operations_n);

    for (auto i : std::views::iota(0, operations_n)) {
        raisers.push_back(i % 10 == 0 ? raise_by_two : raise_by_one);
    }

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    long result = 0;
    for (const auto &current_raiser : raisers) {
        result = current_raiser(result);
    }

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    std::cout << "Took " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << " ms\n";
    std::cout << "Result is " << result << std::endl;

    return 0;
}
