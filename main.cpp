#include <iostream>
#include <memory>

class BaseClass {
public:
    virtual int raise(int number) {
        return number + 1;
    }
};

class Subclass : public BaseClass {
public:
    int raise(int number) override {
        return number + 2;
    }
};

int main(int argc, char *argv[]) {
    //int operations_n = std::stoi(argv[1]);

    auto raiser = std::make_unique<Subclass>();
    std::cout << raiser->raise(0) << std::endl;
    return 0;
}
