#pragma once

#include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
    private:
    public:
        // Iterator Types
        typedef typename std::stack<T>::container_type::iterator iterator;

        // Iterator Functions
        iterator begin();
        iterator end();
};

#include "MutantStack.tpp"
