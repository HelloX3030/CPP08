#include <iostream>

template <typename T>
typename T::iterator easyfind(T& container, int value)
{
    typename T::iterator it;
    for (it = container.begin(); it != container.end(); ++it)
        if (*it == value)
            return it;
    return container.end();
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
