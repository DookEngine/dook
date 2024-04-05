#pragma once
#include <LoggerService.hpp>

namespace dook
{
    class CommonLoggerService : public LoggerService
    {
    private:
        /**
         * @brief Get time stamp of now to print.
         *
         * @return std::string
         */
        std::string time_stamp();

    public:
        CommonLoggerService()
        {
        }
        ~CommonLoggerService() = default;

        /**
         * @brief Log an error to std::cerr
         *
         * @param message
         */
        template <typename... Ms>
        virtual void error(std::string message, Ms... messages) override;

        /**
         * @brief Log a message using std::cout.
         *
         * @param message Message to log.
         */
        template <typename... Ms>
        virtual void log(std::string fmt, Ms... messages) override;
    };
}