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
        virtual void error(std::string message) override;

        /**
         * @brief Log a message using std::cout.
         *
         * @param message Message to log.
         */
        virtual void log(std::string message) override;
    };
}