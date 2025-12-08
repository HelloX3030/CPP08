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
        size_t _size;
        std::vector<int> _data;

    public:
        Span();
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        // Special Constructor
        Span(size_t n);
        void addNumber(int number);
        std::string to_string(bool dataInfo = false, bool spanInfo = false) const;
        int shortestSpan() const;
        int longestSpan() const;
};

template <typename InputIt>
void add_range(Span &span, InputIt begin, InputIt end)
{
    for (InputIt it = begin; it != end; ++it)
        span.addNumber(*it);
}
