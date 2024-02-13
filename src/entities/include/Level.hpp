#pragma once

#include <memory>
#include <string>
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
        std::unique_ptr<Texture<T>> background;
        std::unique_ptr<Texture<T>> foreground;
        std::unique_ptr<Texture<T>> passability;

    public:
        /**
         * @brief Construct a new Level object
         *
         * @param name Entity name of the level.
         * @param background Background texture that will be rendered
         * before the characters.
         * @param foreground Foreground texture that will be rendered
         * in front of the characters.
         * @param passability Passability layer that decides which tiles
         * are passable.
         * @param source Information about source file.
         */
        Level(
            std::string name,
            std::unqiue_ptr<Texture<T>> background,
            std::unqiue_ptr<Texture<T>> foreground,
            std::unqiue_ptr<Texture<T>> passability,
            SourceInfo source)
            : Entity(name, EntityType::LEVEL, source),
              background(background),
              foreground(foreground),
              passability(passability) {}
        /**
         * @brief Construct a new Level object
         *
         * @param name Entity name of the level.
         * @param background Background texture that will be rendered
         * before the characters.
         * @param foreground Foreground texture that will be rendered
         * in front of the characters.
         * @param passability Passability layer that decides which tiles
         * are passable.
         */
        Level(
            std::string name,
            std::unqiue_ptr<Texture<T>> background,
            std::unqiue_ptr<Texture<T>> foreground,
            std::unqiue_ptr<Texture<T>> passability)
            : Level(name, background, foreground, passability);
        ~Level() = default;
    };
};
