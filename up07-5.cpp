#include <boost/date_time/gregorian/gregorian.hpp>
#include <iostream>
#include <sstream>
#include <string>

int main()
{
    std::string str;
    long long sum = 0;
    if (std::cin >> str) {
        std::stringstream firstss(str);
        short unsigned int year, mon, day;
        firstss >> year >> mon >> day;
        boost::gregorian::date prev(year, -mon, -day);
        while (std::cin >> str) {
            std::stringstream ss(str);
            ss >> year >> mon >> day;
            boost::gregorian::date curr(year, mon * (-1), day * (-1));
            sum += std::abs((curr - prev).days());
            prev = curr;
        }
    }
    std::cout << sum << std::endl;
    return 0;
}