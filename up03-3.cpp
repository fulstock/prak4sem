#include <vector>
#include <algorithm>

void process(const std::vector<int> &v1, std::vector<int> &v2)
{
    std::vector<int> v1c(v1);
    std::sort(v1c.begin(), v1c.end());
    auto last = std::unique(v1c.begin(), v1c.end());
    v1c.erase(last, v1c.end());

    auto it1 = v1c.begin();
    auto it2 = v2.begin();
    auto it2erase = v2.begin();
    int index = 0;

    while (index < static_cast<int>(v2.size()) && it1 < v1c.end()) {
        if (*it1 >= 0) {
            if (index != *it1) {
                std::swap(*it2, *it2erase);
                ++it2;
            } else {
                ++it1;
            }
            ++it2erase;
            ++index;
        } else {
            ++it1;
        }
    }
    v2.erase(it2, it2erase);
}