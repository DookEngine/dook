#pragma once

#include <Texture.hpp>
#include <Entity.hpp>
namespace dook
{
    /**
     * @brief Contains information about a single level
     *
     * @tparam T
     * @tparam S
     */
    template <class T, class S>
    class Level : public Entity
    {
    private:
        Texture<T> background;
        Texture<T> foreground;
        Texture<T> passability;
    };
};
