#include <vector>
#include <functional>

template<typename Iter, typename F>
void myapply(Iter BeginIt, Iter EndIt, F pred) {
    for (auto it = BeginIt; it != EndIt; ++it) {
        pred(*it);
    }
}

template<typename Iter, typename F>
auto myfilter2(Iter BeginIt, Iter EndIt, F pred) {
    std::vector<std::reference_wrapper<typename Iter::value_type>> res;
    for (auto it = BeginIt; it != EndIt; ++it) {
        if (pred(*it)) {
            res.insert(res.end(), *it);
        }
    }
    return res;
}

template<typename C, typename  F>
void myapply(C *BeginPtr, C *EndPtr, F pred) {
    for (C *ptr = BeginPtr; ptr != EndPtr; ptr++) {
        pred(*ptr);
    }
}

template<typename C, typename  F>
auto myfilter2(C *BeginPtr, C *EndPtr, F pred) {
    std::vector<std::reference_wrapper<C>> res;
    for (C *ptr = BeginPtr; ptr != EndPtr; ptr++) {
        if (pred(*ptr)) {
            res.insert(res.end(), *ptr);
        }
    }
    return res;
}