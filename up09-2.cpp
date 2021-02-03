#include <iostream>
#include <string>

int check(std::string str)
{
    enum state {H, A, AB, AC, ABC, AS, ABS, ACS, ABCS, ERR};
    state st = H;
    size_t idx = 0;
    size_t len = str.length();
    do {
        switch (st) {
        case H:
        case A:
        case AS:
            if (str[idx] == '0') {
                idx++;
                st = A;
            } else if (str[idx] == '1') {
                idx++;
                st = AB;
            } else {
                st = ERR;
            }
            break;
        case AB:
        case ABS:
            if (str[idx] == '0') {
                idx++;
                st = AC;
            } else if (str[idx] == '1') {
                idx++;
                st = ABC;
            } else {
                st = ERR;
            }
            break;
        case AC:
        case ACS:
            if (str[idx] == '0') {
                idx++;
                st = AS;
            } else if (str[idx] == '1') {
                idx++;
                st = ABS;
            } else {
                st = ERR;
            }
            break;
        case ABC:
        case ABCS:
            if (str[idx] == '0') {
                idx++;
                st = ACS;
            } else if (str[idx] == '1') {
                idx++;
                st = ABCS;
            } else {
                st = ERR;
            }
            break;
        default:
            break;
        }
    } while (st != ERR && idx < len);
    if (st == AS || st == ABS || st == ACS || st == ABCS) {
        return 1;
    }
    return 0;
}

int main()
{
    std::string str;
    while (std::cin >> str) {
        std::cout << check(str) << std::endl;
    }
    return 0;
}