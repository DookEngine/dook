#pragma once

#include <memory>
#include <string>
#include <Texture.hpp>
#include <Entity.hpp>
#include <Character.hpp>
#include <Object.hpp>

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
        const std::unique_ptr<Texture<T>> background;
        const std::unique_ptr<Texture<T>> foreground;
        const std::unique_ptr<Texture<T>> passability;
        std::shared_ptr<Character<T, S>> _main_character;
        std::vector<std::shared_ptr<Character<T, S>>> characters;
        std::vector<std::shared_ptr<Object<T, S>>> objects;

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
            std::unique_ptr<Texture<T>> background,
            std::unique_ptr<Texture<T>> foreground,
            std::unique_ptr<Texture<T>> passability,
            SourceInfo source)
            : Entity(name, EntityType::LEVEL, source),
              background(std::move(background)),
              foreground(std::move(foreground)),
              passability(std::move(passability))
        {
        }
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
            std::unique_ptr<Texture<T>> background,
            std::unique_ptr<Texture<T>> foreground,
            std::unique_ptr<Texture<T>> passability)
            : Level(name,
                    std::move(background),
                    std::move(foreground),
                    std::move(passability),
                    {"", 0}) {}
        ~Level() = default;

        /**
         * @brief Include a character in this level.
         *
         * @param character
         */
        void register_character(std::shared_ptr<Character<T, S>> character);

        /**
         * @brief Get the main character.
         *
         * Character with ID 0 is the main character.
         *
         * @return std::shared_ptr<Character> The main character.
         */
        std::shared_ptr<Character<T, S>> main_character();

        void tick();
    };
};
