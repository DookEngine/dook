#pragma once
#include <memory>
#include <string>
#include <Level.hpp>

namespace dook
{
    /**
     * @brief This service handles level mainloops.
     *
     * Loads levels, and keeps track of the current
     * level.
     */
    class LevelService
    {
    private:
        std::shared_ptr<Level> _level;

    protected:
        /**
         * @brief Set the level object manually.
         */
        void set_level(std::shared_ptr<Level> level);

    public:
        LevelService() : _level(nullptr) {}
        /**
         * @brief Load the level with the given name.
         *
         * @param name Name of the level.
         * @return true If the load is sucessful.
         * @return false otherwise.
         */
        virtual bool load_level(std::string name) = 0;
        virtual std::shared_ptr<Level> current_level();

        /**
         * @brief Tick every single object, make them take action, etc.
         *
         */
        void tick();

        virtual ~LevelService() = default;
    };
};
