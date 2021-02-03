#include <algorithm>
#include <vector>

template <typename IterNum, typename IterMod>
auto myremove (const IterNum &begnum, const IterNum &endnum, const IterMod &begrem, const IterMod &endrem) {

    std::vector<int> v1c(begnum, endnum);
    std::sort(v1c.begin(), v1c.end());
    auto last = std::unique(v1c.begin(), v1c.end());
    v1c.erase(last, v1c.end());

    int index = 0;
    auto newrem = begrem;

    for (auto it2 = begrem; it2 != endrem; ++it2, ++index) {
        bool isMoved = true;
        for (auto el1 : v1c) {
            if (el1 == index) {
                isMoved = false;
                break;
            }
        }
        if (isMoved) {
            *newrem = std::move(*it2);
            ++newrem;
        }
    }

    return newrem;
}