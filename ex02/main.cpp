#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main(void)
{
    std::cout << "------------------------------------------" << std::endl;
    std::cout << "MutantStack test:" << std::endl;
    {
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << mstack.top() << std::endl;
        mstack.pop();
        std::cout << mstack.size() << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        //[...]
        mstack.push(0);
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<int> s(mstack);   
    }

    std::cout << "------------------------------------------" << std::endl;
    std::cout << "List test:" << std::endl;
    {
        std::list<int> mstack;
        mstack.push_back(5);
        mstack.push_back(17);
        std::cout << mstack.back() << std::endl;
        mstack.pop_back();
        std::cout << mstack.size() << std::endl;
        mstack.push_back(3);
        mstack.push_back(5);
        mstack.push_back(737);
        //[...]
        mstack.push_back(0);
        std::list<int>::iterator it = mstack.begin();
        std::list<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
    }

    std::cout << "------------------------------------------" << std::endl;
    std::cout << "Const MutantStack test:" << std::endl;
    {
        MutantStack<int> mstack;
        mstack.push(10);
        mstack.push(20);
        mstack.push(30);
        const MutantStack<int> const_mstack = mstack;
        MutantStack<int>::const_iterator it = const_mstack.begin();
        MutantStack<int>::const_iterator ite = const_mstack.end();
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
    }

    std::cout << "------------------------------------------" << std::endl;
    std::cout << "Reverse MutantStack test:" << std::endl;
    {
        MutantStack<int> mstack;
        mstack.push(100);
        mstack.push(200);
        mstack.push(300);
        MutantStack<int>::reverse_iterator rit = mstack.rbegin();
        MutantStack<int>::reverse_iterator rite = mstack.rend();
        while (rit != rite)
        {
            std::cout << *rit << std::endl;
            ++rit;
        }
    }

    std::cout << "------------------------------------------" << std::endl;
    std::cout << "Const Reverse MutantStack test:" << std::endl;
    {
        MutantStack<int> mstack;
        mstack.push(1000);
        mstack.push(2000);
        mstack.push(3000);
        const MutantStack<int> const_mstack = mstack;
        MutantStack<int>::const_reverse_iterator rit = const_mstack.rbegin();
        MutantStack<int>::const_reverse_iterator rite = const_mstack.rend();
        while (rit != rite)
        {
            std::cout << *rit << std::endl;
            ++rit;
        }
    }
    return 0;
}
