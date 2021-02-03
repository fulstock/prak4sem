template <typename C, typename F>
C myfilter(C& cont, F func)
{
    C filtered;
    for (auto elem : cont) {
        if (func(elem)) {
            filtered.insert(filtered.end(), elem);
        }
    }
    return filtered;
}