#include "RotatedStack.h"

void RotatedStack::Add(int el)
{
    if (elements.size() == Limit)
    {
        elements.pop();
    }

    elements.push(el);
}

std::size_t RotatedStack::Size()
{
    return elements.size();
}