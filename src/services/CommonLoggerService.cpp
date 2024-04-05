#include <CommonLoggerService.hpp>
#include <iostream>
#include <chrono>
#include <iterator>
#include <sstream>
#include <format>

std::string dook::CommonLoggerService::time_stamp()
{
    // Bellow code combines https://en.cppreference.com/w/cpp/chrono/c/strftime
    // and numerous stack overflow answers
    auto now = std::chrono::system_clock::now();
    auto now_in_time_t = std::chrono::system_clock::to_time_t(now);
    char time_str[std::size("yyyy-mm-ddThh:mm:ss")];
    std::strftime(
        std::data(time_str),
        std::size(time_str) - 1,
        "%FT%T",
        std::gmtime(&now_in_time_t));
    std::stringstream output;
    output << time_str;
    return output.str();
}

template <typename... Ms>
void dook::CommonLoggerService::log(std::string fmt, Ms... messages)
{
    auto current_date = this->time_stamp();
    auto message = std::format(fmt, messages...);
    std::cout << current_date << ": " << message << std::endl;
}

template <typename... Ms>
void dook::CommonLoggerService::error(std::string fmt, Ms... messages)
{
    auto current_date = this->time_stamp();
    auto message = std::format(fmt, messages...);
    std::cerr << current_date << ": " << message << std::endl;
}
