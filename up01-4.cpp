#include <iostream>
#include <iomanip>
#include <cmath>

int
main()
{
    double in{0};
    double sum{0};
    long long count = 0;
    double sqsum{0};
    while (std::cin >> in) {
        sum += in;
        sqsum += in*in;
        count++;
    }
    double mean = sum / count;
    std::cout << std::fixed << std::setprecision(10) << mean
        << std::endl << sqrt(sqsum / count - mean * mean) << std::endl;
    return 0;
}