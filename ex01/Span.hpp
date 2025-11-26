#pragma once

#include <stddef.h>

class Span
{
    private:
        size_t _n;
        int* _data;

    public:
        Span();
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        // Special Constructor
        Span(size_t n);
};
