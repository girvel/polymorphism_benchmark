#include <chrono>

// std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
class Timer {
public:
    Timer() : _point(std::chrono::steady_clock::now()) {}

    int ms_elapsed() const {
        return std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::steady_clock::now() - _point
        ).count();
    }

    void reset() {
        _point = std::chrono::steady_clock::now();
    }

private:
    std::chrono::steady_clock::time_point _point;
};
