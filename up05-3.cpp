#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <memory>

class Factory
{
private:
    Factory() {};
public:
    static Factory &factory_instance() {
        static Factory single;
        return single;
    }
    std::unique_ptr<Figure> create_figure(std::string str) {
        std::istringstream strin(str);
        char ftype;
        strin >> ftype;
        std::getline(strin, str);
        switch (ftype) {
        case 'R':
            return std::unique_ptr<Rectangle>(Rectangle::make(str));
        case 'S':
            return std::unique_ptr<Square>(Square::make(str));
        case 'C':
            return std::unique_ptr<Circle>(Circle::make(str));
        }
        return nullptr;
    }
};

bool comp (const std::unique_ptr<Figure> &f1, const std::unique_ptr<Figure> &f2) {
    return (f1->get_square() < f2->get_square());
}

int main()
{
    std::vector<std::unique_ptr<Figure>> vec;
    Factory fact = Factory::factory_instance();
    std::string input;
    while (std::getline(std::cin, input)) {
        vec.push_back(fact.create_figure(input));
    }
    std::stable_sort(vec.begin(), vec.end(), comp);
    for (auto &f : vec) {
        std::cout << f->to_string() << std::endl;
    }
    return 0;
}