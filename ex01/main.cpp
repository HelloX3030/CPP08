#include "Span.hpp"

int main(void)
{
    std::cout << "Test default Constructor" << std::endl;
    Span s4;
    std::cout << s4.to_string() << std::endl;
    
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "Test adding more numbers than the span can hold" << std::endl;
    try
    {
        Span s(10);
        for (int i = 0; i < 11; ++i)
            s.addNumber(i);
        std::cout << s.to_string() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "Test Assignment Operator" << std::endl;
    Span s1(10);
    for (int i = 0; i < 5; ++i)
        s1.addNumber(i);
    Span s2 = s1;
    s2.addNumber(11);
    std::cout << s1.to_string() << std::endl;
    std::cout << s2.to_string() << std::endl;

    std::cout << "----------------------------------------" << std::endl;
    std::cout << "Test Copy Constructor" << std::endl;
    Span s3(s2);
    s3.addNumber(12);
    std::cout << s2.to_string() << std::endl;
    std::cout << s3.to_string() << std::endl;

    // Spans
    std::cout << "----------------------------------------" << std::endl;
    Span s(10);
    for (int i = 0; i < 10; ++i)
        s.addNumber(i);
    std::cout << s.to_string() << std::endl;
    return (0);
}
