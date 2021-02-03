#include <cstdio>
#include <string>
#include <cmath>
#include <iostream>
#include <vector>

#include "cmc_complex.h"
#include "cmc_complex_stack.h"
#include "cmc_complex_eval.h"

int
main (int argc, char *argv[])
{
    numbers::complex c(argv[1]);
    double r;
    int n;
    sscanf(argv[2], "%lf", &r);
    sscanf(argv[3], "%d", &n);
    numbers::complex sum;
    for (int k = 0; k < n; k++) {
        numbers::complex z(c);
        double arg = ((double) k + 1/2) * 2 * M_PI / n;
        z += numbers::complex(r * cos(arg), r * sin(arg));
        std::vector<std::string> evalfunc;
        for (int i = 4; i < argc; i++) {
            evalfunc.push_back(argv[i]);
        }
        sum += numbers::eval(evalfunc, z) * numbers::complex(-sin(arg), cos(arg));
    }
    sum *= numbers::complex(2 * M_PI * r / n);
    std::cout << sum.to_string() << std::endl;