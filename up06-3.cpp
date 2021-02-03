#include <cmath>

namespace Game
{
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
        T rr1 = c1.row - (c1.col + 1) / 2;
        T rr2 = c2.row - (c2.col + 1) / 2;
        T h1 = -(rr1 + c1.col);
        T h2 = -(rr2 + c2.col);
        T max2 = std::max(tabs(rr1 - rr2), tabs(c1.col - c2.col));
        return std::max(max2, tabs(h1 - h2));
    }
};