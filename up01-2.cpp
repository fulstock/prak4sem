#include <iostream>

class A
{
    int num;
    bool isDestr;
public:
    A() : isDestr(false) {
        std::cin >> num;
    }
    A(const A& b) : isDestr(true) {
        int in;
        std::cin >> in;
        num = in + b.num;
    }
    ~A() {
        if(isDestr) {
            std::cout << num << std::endl;
        }
    }
};