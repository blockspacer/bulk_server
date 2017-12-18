#include "ip_filter.h"
#include <iostream>

int main(int, char const**)
{
    try
    {
        otus::pool_t ip_pool;

        for(std::string line; std::getline(std::cin, line);) {
            auto v = otus::split(line, '\t');
            ip_pool.push_back(otus::split(v.at(0), '.'));
        }

        otus::print_reverse(std::cout, ip_pool);
        otus::print_filter(std::cout, ip_pool, 46);
        otus::print_filter(std::cout, ip_pool, 46, 70);
        otus::print_filter_any(std::cout, ip_pool, 46);
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
