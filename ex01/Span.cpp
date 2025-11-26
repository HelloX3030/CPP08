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

std::string Span::to_string(bool spanInfo) const
{
    std::ostringstream oss_addr;
    oss_addr << std::hex << reinterpret_cast<std::uintptr_t>(_data);
    const std::string addr_hex = oss_addr.str();

    std::string result;
    size_t len = 64 + _size * 4 + (spanInfo ? 32 : 0); // Approximate reservation for efficiency
    result.reserve(len); 

    result += "Span: (n: ";
    result += std::to_string(_n);
    result += ", size: ";
    result += std::to_string(_size);
    result += ", _data: 0x";
    result += addr_hex;

    if (spanInfo)
    {
        result += " Shortest Span: " + std::to_string(shortestSpan()) + " ";
        result += "Longest Span: " + std::to_string(longestSpan());
    }
    result += ") ";

    for (size_t i = 0; i < _size; ++i) {
        result += std::to_string(_data[i]);
        result += ' ';
    }

    return result;
}

int Span::shortestSpan() const
{
    if (_size < 2)
        throw std::logic_error("Not enough elements to find a span");

    int *tmp = new int[_size];
    for (size_t i = 0; i < _size; ++i)
        tmp[i] = _data[i];
    
    // Bubble sort
    for (size_t i = 0; i < _size - 1; ++i)
        for (size_t j = i + 1; j < _size; ++j)
            if (tmp[i] > tmp[j])
                std::swap(tmp[i], tmp[j]);

    int shortest = std::numeric_limits<int>::max();
    for (size_t i = 1; i < _size; ++i)
    {
        int diff = tmp[i] - tmp[i - 1];
        if (diff < shortest)
            shortest = diff;
    }

    delete[] tmp;
    return shortest;
}

int Span::longestSpan() const
{
    if (_size < 2)
        throw std::logic_error("Not enough elements to find a span");
    
    int min = std::numeric_limits<int>::max();
    int max = std::numeric_limits<int>::min();
    for (size_t i = 0; i < _size; ++i)
    {
        if (min > _data[i])
            min = _data[i];
        if (max < _data[i])
            max = _data[i];
    }
    return std::abs(max - min);
}
