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

        virtual void error(std::string message) override;
        virtual void log(std::string message) override;
    };
}