#pragma once

#include <LevelService.hpp>
#include <NullLevelService.hpp>

namespace dook
{
    /**
     * @brief Get services safely.
     *
     */
    class ServiceLocator
    {
    private:
        std::unique_ptr<LevelService> _level;
        static std::unique_ptr<ServiceLocator> locator;
        ServiceLocator() : _level(new NullLevelService()) {}

    public:
        /**
         * @brief Register a level service.
         *
         * @param service Level service unique ptr.
         */
        void static provide(std::unique_ptr<LevelService> service);

        /**
         * @brief Get the level service
         *
         * @return LevelService& Reference to level service.
         */
        static LevelService &level();
    };
};
