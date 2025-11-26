#include "easyfind.hpp"
#include <vector>
#include <iostream>


int main(void)
{
    std::vector<int> vec = {1, 2, 3, 4, 5};
    for (size_t i = 0; i < vec.size(); ++i)
        std::cout << vec[i] << " ";
    std::cout << std::endl;
    test(vec, 3);
    test(vec, 6);
    test(vec, 1);
    test(vec, -1);
    return 0;
}
