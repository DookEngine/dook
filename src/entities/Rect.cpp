#include <Rect.hpp>

dook::Rect dook::operator+(dook::Rect left, const dook::Rect &right)
{
    return {
        left.x + right.w,
        left.y + right.h,
        left.w,
        left.h};
}

dook::Rect dook::operator-(dook::Rect left, const dook::Rect &right)
{
    return {
        left.x - right.w,
        left.y - right.h,
        left.w,
        left.h};
}

bool dook::Rect::contains(float x, float y) const
{
    return (this->x < x) && (x < (this->x + this->w)) && (this->y < y) && (y < (this->y + this->h));
}
