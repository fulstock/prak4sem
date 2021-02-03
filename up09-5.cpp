#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

int main()
{
    std::set<char> vprev, vcur;
    std::vector<std::pair<char, std::string>> rules;
    char c;
    std::string str;
    while (std::cin >> c >> str) {
        rules.push_back({c, str});
    }
    vcur.insert('S');
    while (vcur != vprev) {
        vprev = vcur;
        for (auto &elem : rules) {
            if (vprev.count(elem.first)) {
                for (auto &sym : elem.second) {
                    if (std::isupper(sym)) {
                        vcur.insert(sym);
                    }
                }
            }
        }
    }
    for (auto &elem : rules) {
        if (vcur.count(elem.first)) {
            std::cout << elem.first << " " << elem.second << std::endl;
        }
    }
    return 0;
}