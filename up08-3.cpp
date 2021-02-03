#include <iostream>
#include <string>

bool isFullTerminal(const std::string &leftrule) {
    for (char s : leftrule) {
        if (!((s >= '0' && s <= '9') || (s >= 'a' && s <= 'z'))) {
            return false;
        }
    }
    return true;
}

int main(){
    std::string left, right;
    bool fullTerminal = false;
    bool hasStart = false;
    bool isConFree = true;
    bool isShortConFree = true;
    bool isExtra = false;
    bool hasS = false;
    while (std::cin >> left >> right) {
        if (left == "S") {
            hasStart = true;
        }
        if (isFullTerminal(left)) {
            fullTerminal = true;
        }
        if (right == "_") {
            if (left == "S") {
                isExtra = true;
            } else {
                isShortConFree = false;
            }
        }
        if (isFullTerminal(left) || left.length() != 1) {
            isConFree = false;
        }
        if (left.length() > right.length()) {
            isShortConFree = false;
        }
        if (right.find('S') != std::string::npos) {
            hasS = true;
        }
    }
    if (!(!isExtra || !hasS)) {
        isShortConFree = false;
    }
    if (!hasStart || fullTerminal) {
        std::cout << "-1" << std::endl;
    }  else if (isConFree) {
        if (isShortConFree) {
            std::cout << "23" << std::endl;
        } else {
            std::cout << "2" << std::endl;
        }
    } else {
        std::cout << "10" << std::endl;
    }
    return 0;
}