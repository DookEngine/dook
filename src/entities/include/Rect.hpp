#pragma once

namespace dook
{
    class Rect
    {
    public:
        float x;
        float y;
        float w;
        float h;
        Rect(float x, float y, float w, float h) : x(x), y(y), w(w), h(h){};
        Rect() = default;
        ~Rect(){};
        /**
         * @brief Create a new rectangle by shifting wrt to the right rectangle.
         *
         * Shift the left rectangle's position wrt to the right rectangle's width and
         * height, ignore the x and y values of the right rectangle, preserve the width
         * and height of the left rectangle.
         */
        friend Rect operator+(Rect left, const Rect &right);

        /**
         * @brief Reverse of the +
         */
        friend Rect operator-(Rect left, const Rect &right);

        /**
         * @brief Evaluate whether or not a certain x, y coord pair
         * falls within this rectangle.
         *
         * @param x Horizontal offset of the point.
         * @param y Vertical offset of the point.
         * @return true If the point is within the rectangle.
         * @return false If the point is outside the rectangle.
         */
        bool contains(float x, float y) const;
    };
}