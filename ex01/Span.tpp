template <typename It>
void Span::addRange(It begin, It end)
{
    int count = std::distance(begin, end);
    if (_data.size() + count > _n)
        throw std::out_of_range("Adding range exceeds Span capacity");

    _data.insert(_data.end(), begin, end);
}
