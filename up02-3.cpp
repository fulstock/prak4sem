#include <cmath>
#include <string>
#include <vector>
#include <cstring>
#include <map>
#include <functional>

namespace numbers
{
    complex eval(const std::vector<std::string> &args, const complex &z) {
        complex_stack stack;

        std::map < const char, std::function<numbers::complex_stack(numbers::complex_stack&,
                const numbers::complex&)> > mapTable {
                {'+', [](complex_stack &stack, const complex &z) {
                    complex v1, v2;
                    v1 = +stack;
                    stack = ~stack;
                    v2 = +stack;
                    stack = ~stack;
                    stack = (stack << v1 + v2);
                    return stack;
                }},
                {'-', [](complex_stack &stack, const complex &z) {
                    complex v1, v2;
                    v1 = +stack;
                    stack = ~stack;
                    v2 = +stack;
                    stack = ~stack;
                    stack = (stack << v2 - v1);
                    return stack;
                }},
                {'*', [](complex_stack &stack, const complex &z) {
                    complex v1, v2;
                    v1 = +stack;
                    stack = ~stack;
                    v2 = +stack;
                    stack = ~stack;
                    stack = (stack << v1 * v2);
                    return stack;
                }},
                {'/', [](complex_stack &stack, const complex &z) {
                    complex v1, v2;
                    v1 = +stack;
                    stack = ~stack;
                    v2 = +stack;
                    stack = ~stack;
                    stack = (stack << v2 / v1);
                    return stack;
                }},
                {'!', [](complex_stack &stack, const complex &z) {
                    stack = (stack << +stack);
                    return stack;
                }},
                {';', [](complex_stack &stack, const complex &z) {
                    stack = ~stack;
                    return stack;
                }},
                {'~', [](complex_stack &stack, const complex &z) {
                    complex v1 = +stack;
                    stack = ~stack;
                    stack = (stack << ~v1);
                    return stack;
                }},
                {'#', [](complex_stack &stack, const complex &z) {
                    complex v1 = +stack;
                    stack = ~stack;
                    stack = (stack << -v1);
                    return stack;
                }},
                {'z', [](complex_stack &stack, const complex &z) {
                    stack = (stack << z);
                    return stack;
                }}
        };
        for (auto it = args.begin(); it < args.end(); it++) {
            complex v1, v2;
            if ((*it).length() > 1) {
                complex tmp(*it);
                stack = (stack << tmp);
            } else {
                char sym = (*it)[0];
                mapTable[sym](stack, z);
            }
        }
        return +stack;
    }
};