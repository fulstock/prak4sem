#include <complex>
#include <array>
#include <vector>

namespace Equations
{
    template <typename T>
    std::pair<bool, std::vector<std::complex<T>>>
    quadratic(std::array<std::complex<T>, 3> arr) {
        std::complex<T> nullnum {0.0, 0.0};
        std::complex<T> a{arr[2]}, b{arr[1]}, c{arr[0]};
        if (a == nullnum && b == nullnum && c == nullnum) {
            return {false, {}};
        } else if (a == nullnum && b == nullnum) {
            return {true, {}};
        } else if (a == nullnum) {
            return {true, { -c / b }};
        } else {
            std::complex discr = b * b - std::complex<T>{4.0, 0.0} * a * c;
            std::vector<std::complex<T>> vec = {
                (-b + sqrt(discr)) / (std::complex<T>{2.0, 0.0} * a),
                (-b - sqrt(discr)) / (std::complex<T>{2.0, 0.0} * a)
            };
            return {true, vec};
        }
    }
};