#pragma once
#include <istream>
#include <memory>
#include <Level.hpp>
#include <EntityBundle.hpp>

namespace dook
{
    /**
     * @brief Service used to emit entities.
     *
     */
    class ParserService
    {
    protected:
        std::unique_ptr<EntityBundle> _entity_bundle;

        /**
         * @brief Parse the entities in a bundle and return it.
         *
         * @param stream Stream to parse.
         * @return std::unique_ptr<EntityBundle> Pointer to entity bundle.
         */
        [[nodiscard]] virtual const EntityBundle &
        parse_entites(std::istream &stream) = 0;

        /**
         * @brief Parse a level object from an input stream.
         *
         * @param stream Stream to parse.
         * @return std::unique_ptr<Level> Reference to the entity bundle
         */
        [[nodiscard]] virtual const EntityBundle &
        parse_manifest(std::istream &stream) = 0;

        /**
         * @brief Resolve a given resource identifier to a readable stream.
         *
         * @param resource_identifier ID to the resource.
         * @return std::unique_ptr<std::istream> Unique ptr to the input stream.
         */
        [[nodiscard]] virtual std::unique_ptr<std::istream>
        resolve_stream(const std::string &resource_identifier) = 0;

        /**
         * @brief Switch to a specific level
         *
         * @param level_id
         * @return std::unique_ptr<Level>
         */
        [[nodiscard]] virtual std::unique_ptr<Level>
        load_level(std::string level_id) = 0;

    public:
        ParserService() = default;
        virtual ~ParserService() = default;

        /**
         * @brief Get the reference to the entity bundle.
         *
         * @return const EntityBundle& Constant entity bundle reference.
         */
        [[nodiscard]] const EntityBundle &
        entity_bundle() const;

        /**
         * @brief Parse level information from given resource_identifier.
         *
         * @param resource_identifier Some sort of identifier that can be resolved to a stream.
         * @return Level
         */
        [[nodiscard]] const EntityBundle &
        load_manifest(std::string resource_identifier);

        /**
         * @brief Switch the active level.
         *
         * @param level_id Level id to switch to.
         * @return std::shared_ptr<Level> Unique ptr
         */
        [[nodiscard]] virtual std::shared_ptr<Level>
        switch_level(std::string level_id);
    };
} // namespace dook
