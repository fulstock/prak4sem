template<typename C>
auto process(const C &cont) {
    typename C::value_type sum = {};
    if (cont.rbegin() == cont.rend()) {
        return sum;
    }
    int idx = 0;
    for (auto it = cont.rbegin(); it != cont.rend() && idx < 5; ++it, ++idx) {
        if (idx == 0 || idx == 2 || idx == 4) {
            sum += *it;
        }
    }
    return sum;
}