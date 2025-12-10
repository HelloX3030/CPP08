#pragma once

#include <stddef.h>
#include <stdexcept>
#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <vector>
#include <algorithm>
#include <numeric>

class Span
{
    private:
        size_t _n;
        std::vector<int> _data;

    public:
        Span();
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        // Special Constructor
        Span(size_t n);
        void addNumber(int number);
        template <typename It> void addRange(It begin, It end);
        std::string to_string(bool dataInfo = true, bool spanInfo = true) const;
        int shortestSpan() const;
        int longestSpan() const;
};

#include "Span.tpp"
