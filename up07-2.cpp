#include <iostream>
#include <cstdint>

// this is original Ackermann function of three arguments

class Result
{
    int64_t res;
public:
    Result(int64_t res) : res {res} {};
    int64_t get_res() const {
        return res;
    }
};

void func (int64_t a, int64_t b, uint32_t k) {
    if (k == 0) {
        throw Result {a + b};
    } else if (b == 1) {
        throw Result {a};
    } else {
        try {
            func(a, b - 1, k);
        } catch (const Result& res) {
            try {
                func(a, res.get_res(), k - 1);
            } catch (const Result &newres) {
                throw newres;
            }
        }
    }
}

int main ()
{
    int64_t a, b;
    uint64_t k;
    while (std::cin >> a >> b >> k) {
        try {
            func(a, b, k);
        } catch (const Result &res) {
            std::cout << res.get_res() << std::endl;
        }
    }
    return 0;
}