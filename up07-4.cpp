#include <iostream>
#include <string>

int main(){
    std::string input;
    std::cin >> input;
    int state = 0; // s = 0, a = 1, b = 2, c = 3, d = 4, finish = 5
    size_t len = input.length();
    ssize_t idx = 0;
    while (state != 5 && idx >= 0 && static_cast<size_t>(idx) < len) {
        switch (state) {
        case 0: // state S
            if (input[idx] == '0') {
                idx++;
            } else if (input[idx] == '1') {
                state = 1;
                idx++;
            } else if (input[idx] == '#') {
                idx++;
            }
            break;
        case 1: // state A
            if (input[idx] == '0') {
                idx++;
            } else if (input[idx] == '1') {
                state = 0;
                idx++;
            } else if (input[idx] == '#') {
                state = 2;
                idx--;
            }
            break;
        case 2: // state B
            if (input[idx] == '0') {
                idx--;
            } else if (input[idx] == '1') {
                idx--;
            } else if (input[idx] == '#') {
                state = 3;
                idx++;
            }
            break;
        case 3: // state C
            if (input[idx] == '0') {
                idx++;
            } else if (input[idx] == '1') {
                state = 5;
                input[idx] = '0';
            }
            break;
        default:
            break;
        }
    }
    std::cout << input << std::endl;
}