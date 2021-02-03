#include <vector>
#include <cstdint>

void process(const std::vector<uint64_t> &c_vec, std::vector<uint64_t> &vec, int stride)
{
    auto c_it = c_vec.begin();
    for (auto it = vec.rbegin(); c_it < c_vec.end() && it < vec.rend(); ++it) {
        *it += *c_it;
        if (std::distance(c_it, c_it + stride) <= stride) {
            c_it += stride;
        }
    }
}