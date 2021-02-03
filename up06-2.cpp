#include <cmath>

template <typename T>
class Coord
{
public:
    typedef T value_type;
    T row, col;
    Coord (T row = 0, T col = 0) : row {row}, col {col} {}
};

template <typename T>
T tabs(T a) {
    if (a >= 0) {
        return a;
    } else {
        return -a;
    }
}

template <typename T>
T dist (Coord<T> size, Coord<T> c1, Coord<T> c2) {
    T tmpsize = std::min(tabs(c2.row - c1.row - size.row), tabs(c2.row - c1.row + size.row));
    T dr = std::min(tabs(c2.row - c1.row), tmpsize);
    tmpsize = std::min(tabs(c2.col - c1.col - size.col), tabs(c2.col - c1.col + size.col));
    T dc = std::min(tabs(c2.col - c1.col), tmpsize);
    return tabs(dr - dc) + std::min(dr, dc);
}