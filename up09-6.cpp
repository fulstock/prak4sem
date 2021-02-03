#include <iostream>
#include <string>
#include <vector>
#include <map>

int main()
{
    std::map<std::pair<std::string, char>, std::string> trans {};
    std::string cur, chr, newstr;
    std::string str;
    while (std::cin) {
        std::cin >> cur;
        if (cur == "END")
            break;
        std::cin >> chr >> newstr;
        trans.insert({{cur, chr[0]}, newstr});
    }
    std::vector<std::string> endstates {};
    while (std::cin >> str && str != "END") {
        endstates.push_back(str);
    }
    std::string state, check;
    std::cin >> state >> str;
    size_t count = 0;
    for (; count < str.length(); count++) {
        if ((check = trans[{state, str[count]}]).empty()) {
            break;
        }
        state = check;
    }
    bool flag = false;
    for (auto &es : endstates) {
        if (state == es && !check.empty()) {
            flag = true;
            break;
        }
    }
    std::cout << flag << std::endl << count << std::endl
        << state << std::endl;
    return 0;
}