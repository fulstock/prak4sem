#include <iostream>
#include <vector>
#include <algorithm>

class Functor
{
    double sum;
public:
    Functor() : sum(0.0) {}
    void operator () (double x) {
        sum += x;
    }
    double get_sum() {
        return sum;
    }
};

int main()
{
    std::vector<double> vec;
    double x;
    while (std::cin >> x) {
        vec.push_back(x);
    }
    int size = vec.size();
    auto beg = vec.begin() + size / 10;
    auto end = vec.end() - size / 10;
    std::sort(beg, end);
    size = static_cast<int>(std::distance(beg, end));
    beg += size / 10;
    end -= size / 10;
    size = static_cast<int>(std::distance(beg, end));
    Functor func = std::for_each(beg, end, Functor());
    std::cout << func.get_sum() / size << std::endl;
    return 0;
}