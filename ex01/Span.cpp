#include "Span.hpp"

Span::Span()
    : _n(0),  _size(0), _data(nullptr)
{
}

Span::Span(const Span& other)
    : _n(other._n), _size(other._size), _data(nullptr)
{
    if (other._data)
    {
        _data = new int[_n];
        for (size_t i = 0; i < _n; ++i)
            _data[i] = other._data[i];
    }
}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        _n = other._n;
        _size = other._size;
        delete[] _data;
        if (other._data)
        {
            _data = new int[_n];
            for (size_t i = 0; i < _n; ++i)
                _data[i] = other._data[i];
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
    : _n(n), _size(0), _data(new int[n])
{
}

void Span::addNumber(int number)
{
    if (_size < _n)
    {
        _data[_size] = number;
        ++_size;
    }
    else
        throw std::out_of_range("Span is already full");
}

std::string Span::to_string() const
{
    std::ostringstream oss_addr;
    oss_addr << std::hex << reinterpret_cast<std::uintptr_t>(_data);
    const std::string addr_hex = oss_addr.str();

    std::string result;
    result.reserve(64 + _size * 4); // assumption: reduce reallocations

    result += "Span: (n: ";
    result += std::to_string(_n);
    result += ", size: ";
    result += std::to_string(_size);
    result += ", _data: 0x";
    result += addr_hex;
    result += ") ";

    for (size_t i = 0; i < _size; ++i) {
        result += std::to_string(_data[i]);
        result += ' ';
    }

    return result;
}
