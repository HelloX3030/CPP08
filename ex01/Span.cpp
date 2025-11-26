#include "Span.hpp"

Span::Span()
    : _n(0), _data(nullptr)
{
}

Span::Span(const Span& other)
    : _n(other._n), _data(nullptr)
{
    if (other._data)
    {
        _data = new int[_n];
        for (size_t i = 0; i < _n; ++i)
        {
            _data[i] = other._data[i];
        }
    }
}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        _n = other._n;
        delete[] _data;
        if (other._data)
        {
            _data = new int[_n];
            for (size_t i = 0; i < _n; ++i)
            {
                _data[i] = other._data[i];
            }
        }
        else
            _data = nullptr;
    }
    return *this;
}

Span::~Span()
{
    delete[] _data;
}

Span::Span(size_t n)
    : _n(n), _data(new int[n])
{
}
