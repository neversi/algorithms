#include "quick_sort.hpp"

#include <iostream>
#include <algorithm>
#include <stdexcept>

int main()
{
    std::mt19937 twister{};
    std::uniform_int_distribution<int> dist{0, 100};
    for (std::size_t i = 0; i <= 30'000; ++i)
    {
        std::vector<int> v(i);
        std::generate(v.begin(), v.end(), [&dist, &twister]{return dist(twister);});

        std::cout << "sorting vector of size " << i << '\n';
        shino::randomized_quicksort(v.begin(), v.end());
        if (not std::is_sorted(v.begin(), v.end()))
            throw std::logic_error("incorrect sorting on size " + std::to_string(i));
    }
}