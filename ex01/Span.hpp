#pragma once

#include <stddef.h>
#include <stdexcept>
#include <iostream>
#include <string>
#include <sstream>
#include <limits>

class Span
{
    private:
        size_t _n;
        size_t _size;
        int* _data;

    public:
        Span();
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        // Special Constructor
        Span(size_t n);
        void addNumber(int number);
        std::string to_string(bool spanInfo = false) const;
        int shortestSpan() const;
        int longestSpan() const;
};
