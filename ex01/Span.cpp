#include "Span.hpp"

Span::Span()
    : _n(0),  _size(0), _data()
{
}

Span::Span(const Span& other)
    : _n(other._n), _size(other._size), _data(other._data)
{

}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        _n = other._n;
        _size = other._size;
        _data = other._data;
    }
    return *this;
}

Span::~Span()
{

}

Span::Span(size_t n)
    : _n(n), _size(0), _data()
{
    _data.resize(n);
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

std::string Span::to_string(bool dataInfo, bool spanInfo) const
{
    std::string result;
    size_t len = 64 + (dataInfo ? _size * 4 : 0) + (spanInfo ? 32 : 0); // Approximate reservation for efficiency
    result.reserve(len); 

    result += "Span: (n: ";
    result += std::to_string(_n);
    result += ", size: ";
    result += std::to_string(_size);

    if (spanInfo)
    {
        result += " Shortest Span: " + std::to_string(shortestSpan()) + " ";
        result += "Longest Span: " + std::to_string(longestSpan());
    }
    result += ") ";

    if (dataInfo)
    {
        for (size_t i = 0; i < _size; ++i) {
            result += std::to_string(_data[i]);
            result += ' ';
        }
    }
    return result;
}

int Span::shortestSpan() const
{
    if (_size < 2)
        throw std::logic_error("Not enough elements to find a span");

    std::vector<int> tmp(_data.begin(), _data.begin() + _size);
    std::sort(tmp.begin(), tmp.end());
    std::vector<int> diffs(tmp.size());
    std::adjacent_difference(tmp.begin(), tmp.end(), diffs.begin());
    int shortest = *std::min_element(diffs.begin() + 1, diffs.end());
    return shortest;
}

int Span::longestSpan() const
{
    if (_size < 2)
        throw std::logic_error("Not enough elements to find a span");

    auto [min_it, max_it] = std::minmax_element(_data.begin(), _data.begin() + _size);
    return std::abs(*max_it - *min_it);
}
