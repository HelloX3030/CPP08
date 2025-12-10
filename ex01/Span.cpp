#include "Span.hpp"

Span::Span()
    : _n(0), _data()
{
}

Span::Span(const Span& other)
    : _n(other._n), _data(other._data)
{

}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        _n = other._n;
        _data = other._data;
    }
    return *this;
}

Span::~Span()
{

}

Span::Span(size_t n)
    : _n(n), _data()
{
    _data.reserve(n);
}

void Span::addNumber(int number)
{
    if (_data.size() < _n)
        _data.push_back(number);
    else
        throw std::out_of_range("Span is already full");
}

std::string Span::to_string(bool dataInfo, bool spanInfo) const
{
    std::string result;

    result += "Span: (n: ";
    result += std::to_string(_n);
    result += ", size: ";
    result += std::to_string(_data.size());

    if (spanInfo)
    {
        std::string shortestSpanStr;
        try {
            shortestSpanStr = std::to_string(shortestSpan());            
        } catch (const std::exception& e) {
            shortestSpanStr = "N/A";
        }
        result += ", Shortest Span: " + shortestSpanStr + ", ";
        std::string longestSpanStr;
        try {
            longestSpanStr = std::to_string(longestSpan());
        } catch (const std::exception& e) {
            longestSpanStr = "N/A";
        }
        result += "Longest Span: " + longestSpanStr;
    }
    result += ") ";

    if (dataInfo)
    {
        result += "Data: ";
        for (size_t i = 0; i < _data.size(); ++i) {
            result += std::to_string(_data[i]);
            result += ' ';
        }
    }
    return result;
}

int Span::shortestSpan() const
{
    if (_data.size() < 2)
        throw std::logic_error("Not enough elements to find a span");

    std::vector<int> tmp(_data.begin(), _data.end());
    std::sort(tmp.begin(), tmp.end());
    std::vector<int> diffs(tmp.size());
    std::adjacent_difference(tmp.begin(), tmp.end(), diffs.begin());
    int shortest = *std::min_element(diffs.begin() + 1, diffs.end());
    return shortest;
}

int Span::longestSpan() const
{
    if (_data.size() < 2)
        throw std::logic_error("Not enough elements to find a span");

    auto [min_it, max_it] = std::minmax_element(_data.begin(), _data.end());
    return std::abs(*max_it - *min_it);
}
