#pragma once

#include <stack>

class RotatedStack
{
public:
    void Add(int el);
    std::size_t Size();

private:
    std::stack<int> elements;
    const std::size_t Limit = 10;
};