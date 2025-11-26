#pragma once

template <typename T>
typename T::iterator easyfind(T& container, int value);

template <typename T>
void test(T &container, int value);

#include "easyfind.tpp"
