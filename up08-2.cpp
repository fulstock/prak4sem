#include <iostream>
#include <string>

int main()
{
    int c;
    c = getchar();
    while(isspace(c)) {
        c = getchar();
    }
    while (c != EOF) {
        while (isspace(c)) {
            c = getchar();
        }
        if (c == EOF) {
            break;
        }
        int zeros_start = 0;
        int ones_start = 0;
        while (c == '0') {
            zeros_start++;
            c = getchar();
        }
        if (zeros_start == 0) {
            std::cout << "0" << std::endl;
            while (!isspace(c) && c != EOF) {
                c = getchar();
            }
            continue;
        }
        if (c == '1') {
            while (c == '1') {
                ones_start++;
                c = getchar();
            }
            if (c == '0') {
                bool ended = true;
                while (c == '0') {
                    int zeros = 0;
                    int ones = 0;
                    while (c == '0') {
                        zeros++;
                        c = getchar();
                    }
                    while (c == '1') {
                        ones++;
                        c = getchar();
                    }
                    if (zeros != zeros_start || ones != ones_start ||
                            (c != '0' && !isspace(c) && c != EOF)) {
                        ended = false;
                        std::cout << "0" << std::endl;
                        while (!isspace(c) && c != EOF) {
                            c = getchar();
                        }
                        break;
                    }
                }
                if (ended) {
                    std::cout << "1" << std::endl;
                }
            } else if (isspace(c) || c == EOF) {
                std::cout << "1" << std::endl;
            } else {
                std::cout << "0" << std::endl;
                while (!isspace(c) && c != EOF) {
                    c = getchar();
                }
            }
        } else if (isspace(c) || c == EOF) {
            std::cout << "0" << std::endl;
        } else {
            std::cout << "0" << std::endl;
            while (!isspace(c) && c != EOF) {
                c = getchar();
            }
        }
    }
    return 0;
}