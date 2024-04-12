#pragma once
#include <istream>
#include <memory>
#include <Level.hpp>

namespace dook
{
    class ParserService
    {
    public:
        /**
         * @brief Parse level information from given input stream.
         *
         * @param input Stream to read from.
         * @return Level
         */
        virtual std::unqiue_ptr<Level> parse_level(std::istream input) = 0;
    }
} // namespace dook
