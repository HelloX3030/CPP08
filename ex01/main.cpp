#include "Span.hpp"
#include <vector>
#include <list>

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
    {
        std::cout << "----------------------------------------" << std::endl;
        std:: cout << "Shortest Span vs Longest Span" << std::endl;
        Span s(10);
        for (int i = 0; i < 10; ++i)
            s.addNumber(5 + (i + 2) * i);
        std::cout << s.to_string(true, true) << std::endl;
    }

    {
        std::cout << "----------------------------------------" << std::endl;
        std:: cout << "Shortest Span vs Longest Span with negative numbers" << std::endl;
        Span s(10);
        for (int i = 0; i < 10; ++i)
            s.addNumber(-50 + i * i);
        std::cout << s.to_string(true, true) << std::endl;
    }

    {
        std::cout << "----------------------------------------" << std::endl;
        std::cout << "Large test according to subject" << std::endl;
        Span s(10000);
        for (int i = 0; i < 10000; ++i)
            s.addNumber(i * 2 - 100);
        std::cout << s.to_string(false, true) << std::endl;
    }
    {
        std::cout << "----------------------------------------" << std::endl;
        std::cout << "Subject Test" << std::endl;
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    {
        Span sp(10);
        std::vector<int> vec = {5, 3, 9, 1};
        add_range(sp, vec.begin(), vec.end());
        std::list<int> lst = {7, 2};
        add_range(sp, lst.begin(), lst.end());
        int arr[] = {10, 6};
        add_range(sp, arr, arr + 2);
        try {
            std::cout << sp.to_string(true, true) << std::endl;
        } catch (const std::exception &e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
    return (0);
}
