#pragma once
#include <ParserService.hpp>

namespace dook
{
    class NullParserService : public ParserService
    {
    protected:
        [[nodiscard]] virtual const EntityBundle &
        parse_entites(std::unique_ptr<std::istream> stream) override;

        [[nodiscard]] virtual const EntityBundle &
        parse_manifest(std::unique_ptr<std::istream> stream) override;

        [[nodiscard]] virtual std::unique_ptr<std::istream>
        resolve_stream(const std::string &resource_identifier) override;

        [[nodiscard]] virtual std::shared_ptr<Level>
        load_level(std::string level_id) override;

    public:
        using ParserService::ParserService;
    };
} // namespace dook
