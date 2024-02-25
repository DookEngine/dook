#pragma once

#include <LevelService.hpp>
#include <NullLevelService.hpp>
#include <GraphicsService.hpp>
#include <NullGraphicsService.hpp>
#include <LoggerService.hpp>
#include <NullLoggerService.hpp>
#include <Texture.hpp>

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
        std::unique_ptr<GraphicsService> _graphics;
        std::unique_ptr<LoggerService> _logger;
        static std::unique_ptr<ServiceLocator> locator;
        ServiceLocator() : _level(new NullLevelService()), _graphics(new NullGraphicsService()), _logger(new NullLoggerService()) {}

    public:
        /**
         * @brief Register a level service.
         *
         * @param service Level service unique ptr.
         */
        void static provide(std::unique_ptr<LevelService> service);

        /**
         * @brief Register a graphics service.
         *
         * @param service Graphics service to register.
         */
        void static provide(std::unique_ptr<GraphicsService> service);

        /**
         * @brief Register a logger service.
         *
         * @param service Logger service to register.
         */
        void static provide(std::unique_ptr<LoggerService> service);

        /**
         * @brief Get the level service
         *
         * @return LevelService& Reference to level service.
         */
        static LevelService &level();

        /**
         * @brief Get the registered graphics service.
         *
         * @return GraphicsService& Reference to graphics server.
         */
        static GraphicsService &graphics();

        /**
         * @brief Get the registered logger.
         *
         * @return LoggerService& Reference to the logger.
         */
        static LoggerService &logger();
    };
};
