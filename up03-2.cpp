#include <vector>
#include <cstdint>

void process(std::vector<int64_t> &vec, int64_t threshold)
{
    int count = 0;
    for (auto it = vec.begin(); it < vec.end(); ++it) {
        if (*it >= threshold) {
            ++count;
        }
    }
    vec.reserve(vec.size() + count);
    for (auto it = vec.rbegin(); it < vec.rend(); ++it) {
        if (*it >= threshold) {
            vec.push_back(*it);
        }
    }
}