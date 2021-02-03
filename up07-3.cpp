#include <iostream>

class S
{
    int num;
    bool flag;
    bool isempty;
public:
    S() : num {0} , flag {true} , isempty {true} {
        if (std::cin >> num) {
            flag = true;
        } else {
            flag = false;
        }
    }
    S(S &&other) : num {0} , flag {true} , isempty {false} {
        if (std::cin >> num) {
            flag = true;
        } else {
            flag = false;
        }
        num += other.num;
        other.isempty = true;
    }
    operator bool() const {
        return flag;
    }
    ~S() {
        if (!isempty) {
            std::cout << num << std::endl;
        }
    }
};