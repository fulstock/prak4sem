#include <string>
#include <iostream>

int check (std::string str) {
    size_t idx = 0;
    int flag = 1;
    size_t len = str.length();
    while (idx < len && (str[idx] == '3' || str[idx] == '4')) {
        idx++;
    }
    while (idx < len && (str[idx] == '1' || str[idx] == '2')) {
        idx++;
    }
    if (idx < len) {
        flag = 0;
    }
    return flag;
}

int main()
{
    std::string str;
    while (std::cin >> str) {
        std::cout << check(str) << std::endl;
    }
}