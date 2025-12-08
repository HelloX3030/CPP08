#include <iostream>

template <typename T>
typename T::iterator easyfind(T& container, int value)
{
    return std::find(container.begin(), container.end(), value);
}

template <typename T>
void test(T &container, int value)
{
    std::cout << "--------------------------------" << std::endl;
    std::cout << "Searching for: " << value << std::endl;
    auto it = easyfind(container, value);
    if (it != container.end())
        std::cout << "Found: " << *it << std::endl;
    else
        std::cout << "Not found" << std::endl;
}
