#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

class Rectangle : public Figure
{
public:
    double a, b;
    double get_square() const {
        return a * b;
    }
    static Rectangle *make (std::string str) {
        std::istringstream strin(str);
        double an, bn;
        strin >> an >> bn;
        Rectangle *rec = new Rectangle;
        rec->a = an;
        rec->b = bn;
        return rec;
    }
};

class Square : public Figure
{
public:
    double a;
    double get_square() const {
        return a * a;
    }
    static Square *make (std::string str) {
        std::istringstream strin(str);
        double an;
        strin >> an;
        Square *sq = new Square;
        sq->a = an;
        return sq;
    }
};

class Circle : public Figure
{
public:
    double r;
    double get_square() const {
        return M_PI * r * r;
    }
    static Circle* make (std::string str) {
        std::istringstream strin(str);
        double rn;
        strin >> rn;
        Circle *cir = new Circle;
        cir->r = rn;
        return cir;
    }
};