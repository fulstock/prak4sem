#include <cmath>
#include <string>

namespace numbers
{
    constexpr int MAX_STR_SIZE = 1000;
    class complex
    {
        double _re, _im;
    public:
        complex (double re = 0.0, double im = 0.0) : _re{re}, _im{im} {}
        explicit complex (std::string str) :  _re{0}, _im{0} {
            sscanf(str.c_str(), "(%lf,%lf)", &_re, &_im);
        }
        double re() const {
            return _re;
        }
        double im() const {
            return _im;
        }
        double abs2() const {
            return _re * _re + _im * _im;
        }
        double abs() const {
            return sqrt(abs2());
        }
        std::string to_string() const {
            char s [MAX_STR_SIZE];
            snprintf(s, MAX_STR_SIZE, "(%.10g,%.10g)", _re, _im);
            return s;
        }
        const complex& operator+= (const complex &other) {
            _re += other.re();
            _im += other.im();
            return *this;
        }
        const complex& operator-= (const complex &other) {
            _re -= other.re();
            _im -= other.im();
            return *this;
        }
        const complex& operator*= (const complex &other) {
            double tmp_re = _re * other.re() - _im * other.im();
            double tmp_im = _im * other.re() + _re * other.im();
            _re = tmp_re;
            _im = tmp_im;
            return *this;
        }
        const complex& operator/= (const complex &other) {
            double tmp_re = (_re * other.re() + _im * other.im())
                            / other.abs2();
            double tmp_im = (_im * other.re() - _re * other.im())
                            / other.abs2();
            _re = tmp_re;
            _im = tmp_im;
            return *this;
        }
        const complex operator~() const {
            return complex(_re, -_im);
        }
        const complex operator-() const {
            return complex(-_re, -_im);
        }
    };
    complex operator+ (const complex &v1, const complex &v2) {
        complex res(v1.re(), v1.im());
        return res += v2;
    }
    complex operator- (const complex &v1, const complex &v2) {
        complex res(v1.re(), v1.im());
        return res -= v2;
    }
    complex operator* (const complex &v1, const complex &v2) {
        complex res(v1.re(), v1.im());
        return res *= v2;
    }
    complex operator/ (const complex &v1, const complex &v2) {
        complex res(v1.re(), v1.im());
        return res /= v2;
    }
};