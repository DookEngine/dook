#pragma once

#include <string>
namespace dook
{
    /**
     * @brief Used to log events.
     */
    class LoggerService
    {
    public:
        LoggerService() = default;
        virtual ~LoggerService() = default;

        /**
         * @brief Log a message to... somewhere.
         *
         * @param message
         */
        template <typename... Ms>
        virtual void log(std::string message, Ms... messages) = 0;

        /**
         * @brief Log an error to... somewhere.
         *
         * @param message
         */

        template <typename... Ms>
        virtual void error(std::string message, Ms... messages) = 0;
    };
}