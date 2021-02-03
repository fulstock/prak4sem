#include <iostream>
#include <string>

// S -> XY
// X -> aXb | ab
// Y -> PY1 | P1
// bP -> Pb
// aP -> a0
// 0P -> 00

int check (std::string str)
{
    size_t idx = 0;
    int flag = 1;
    size_t len = str.length();
    int n = 0;
    int m = 0;
    while (idx < len && str[idx] == 'a') {
        idx++;
        n++;
    }
    while (idx < len && str[idx] == '0') {
        idx++;
        m++;
    }
    int count_n = 0;
    int count_m = 0;
    while (idx < len && str[idx] == 'b') {
        idx++;
        count_n++;
    }
    while (idx < len && str[idx] == '1') {
        idx++;
        count_m++;
    }
    if (idx < len || n == 0 || m == 0 || count_n != n || count_m != m) {
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
    return 0;
}