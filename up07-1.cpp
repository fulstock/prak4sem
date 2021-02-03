#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <memory>

class Reverse
{
private:
    std::string str;
public:
    Reverse () = default;
    Reverse (std::string str) : str {str} {};
    Reverse (const Reverse &other) : str {other.str} {}
    ~Reverse() {
        std::cout << str << std::endl;
    }
};

void f() {
    std::string str;
    if (std::cin >> str) {
        Reverse tmp {str};
        try {
            f();
        } catch (const int x) {
            throw 2;
        }
    } else {
        throw 2;
    }
}

int main()
{
    try {
        f();
    } catch (const int x) {}
    return 0;
}