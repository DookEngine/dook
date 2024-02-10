#pragma once
#include "Rect.hpp"
#include <string>
#include <optional>

namespace dook
{
    class Texture
    {
    private:
        std::string fileName;
        Rect drawRectangle;
        std::optional<Rect> animationStep;

    public:
        Texture(std::string fileName) : fileName(fileName){};
        virtual void animate() = 0;
        virtual ~Texture() = 0;
    }
}