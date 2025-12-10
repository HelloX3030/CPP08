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
        Span s(5);
        for (int i = 0; i < 11; ++i) {
            s.addNumber(i);
            std::cout << s.to_string() << std::endl;
        }
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
    std::cout << s1.to_string() << std::endl;
    std::cout << s2.to_string() << std::endl;
    std::cout << "Adding number to new Span" << std::endl;
    s2.addNumber(11);
    std::cout << s1.to_string() << std::endl;
    std::cout << s2.to_string() << std::endl;

    std::cout << "----------------------------------------" << std::endl;
    std::cout << "Test Copy Constructor" << std::endl;
    Span s3(s2);
    std::cout << s2.to_string() << std::endl;
    std::cout << s3.to_string() << std::endl;
    std::cout << "Adding number to new Span" << std::endl;
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
        std::cout << "----------------------------------------" << std::endl;
        std::cout << "Test addRange with different container types" << std::endl;
        try {
            Span sp(5000);
            std::vector<int> vec = {5, 3, 9, 1};
            std::cout << "Adding vector: ";
            for (size_t i = 0; i < vec.size(); ++i)
                std::cout << vec[i] << " ";
            std::cout << std::endl;
            sp.addRange(vec.begin(), vec.end());
            std::list<int> lst = {7, 2};
            std::cout << "Adding list: ";
            for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
                std::cout << *it << " ";
            std::cout << std::endl;
            sp.addRange(lst.begin(), lst.end());
            int arr[] = {10, 6};
            std::cout << "Adding array: ";
            for (size_t i = 0; i < sizeof(arr)/sizeof(arr[0]); ++i)
                std::cout << arr[i] << " ";
            std::cout << std::endl;
            sp.addRange(arr, arr + 2);
            std::cout << sp.to_string(true, true) << std::endl;
        } catch (const std::exception &e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
    return (0);
}
