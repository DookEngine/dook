#pragma once
#include <istream>
#include <memory>
#include <Level.hpp>

namespace dook
{
    /**
     * @brief Service used to emit entities.
     *
     */
    class ParserService
    {
    protected:
        /**
         * @brief Parse a level object from an input stream.
         *
         * @param stream Stream to parse.
         * @return std::unique_ptr<Level> Pointer to the level.
         */
        [[nodiscard]] virtual std::unique_ptr<Level>
        parse_level(const std::istream &stream) = 0;

        /**
         * @brief Resolve a given resource identifier to a readable stream.
         *
         * @param resource_identifier ID to the resource.
         * @return std::unique_ptr<std::istream> Unique ptr to the input stream.
         */
        [[nodiscard]] virtual std::unique_ptr<std::istream>
        resolve_stream(const std::string &resource_identifier) = 0;

    public:
        ParserService() = default;
        /**
         * @brief Parse level information from given resource_identifier.
         *
         * @param resource_identifier Some sort of identifier that can be resolved to a stream.
         * @return Level
         */
        std::unique_ptr<Level>
        parse_level(std::string resource_identifier);
    };
} // namespace dook
