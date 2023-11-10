#include "DxLib.h"

template<typename InputIterator>
void printall(InputIterator first, InputIterator last)
{
    for (; first != last; ++first)
    {
        std::cout << *first << std::endl;
    }
}