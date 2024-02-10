#include <Rect.hpp>
#include <iostream>

int main()
{
    dook::Rect a{0, 0, 5, 5};
    dook::Rect b{0, 0, 2, 3};
    auto c = a + b;
    std::cout << c.x << " " << c.y << " " << c.w << " " << c.h << std::endl;
}