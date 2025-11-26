#include "Span.hpp"

int main(void)
{
    Span s(10);
    for (int i = 0; i < 3; ++i)
        s.addNumber(i);
    std::cout << s.to_string() << std::endl;
    return (0);
}
