#include <sorting/heap_sort.hpp>

#include <algorithm>
#include <iostream>
#include <numeric>
#include <random>
#include <vector>

#include "testing_config.hpp"

std::vector<int> generate_vector(std::size_t size)
{
    if (size == 0)
        return {};
    if (size == 1)
        return {0};

    static std::mt19937 twister{};
    std::vector<int> numbers(size);
    std::iota(numbers.begin(), numbers.end(), 0);
    std::shuffle(numbers.begin(), numbers.end(), twister);

    return numbers;
}

#include <algorithm>

int main()
{
    for (std::size_t i = 0; i <= test_size_max; ++i)
    {
        std::vector<int> v(generate_vector(i));

        std::cout << "heapifying vector of size " << i << '\n';
        shino::build_heap(v.begin(), v.end());
        if (not std::is_heap(v.begin(), v.end()))
            std::cerr << "incorrect heapifying on size " << i << '\n';

        shino::sort_heap(v.begin(), v.end());
        if (not std::is_sorted(v.begin(), v.end()))
            std::cerr << "incorrect heap sorting on size " << i << '\n';
    }
}
