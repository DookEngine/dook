#pragma once
#include <LoggerService.hpp>

namespace dook
{
    class NullLoggerService : public LoggerService
    {
    public:
        using LoggerService::LoggerService;
        ~NullLoggerService() = default;

        /**
         * @brief Log a message to the empty nothingness.
         *
         */
        virtual void log(std::string) override
        {
            return;
        }

        /**
         * @brief Log an error to empty nothingness.
         */
        virtual void error(std::string) override
        {
            return;
        }
    };
}