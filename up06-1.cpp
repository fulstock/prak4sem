#include <iostream>
#include <cmath>

int main()
{
    int n, m;
    std::cin >> m >> n;
    int r1, c1, r2, c2;
    while (std::cin >> r1 >> c1 >> r2 >> c2) {
        int dr = std::min(abs(r2 - r1), abs(abs(r2 - r1) - m));
        int dc = std::min(abs(c2 - c1), abs(abs(c2 - c1) - n));
        std::cout << (dr + dc) << std::endl;
    }
    return 0;
}