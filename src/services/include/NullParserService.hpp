#pragma once
#include <ParserService.hpp>

namespace dook
{
    class NullParserService : public ParserService
    {
    protected:
        [[nodiscard]] virtual std::unique_ptr<EntityBundle>
        parse_entites(std::istream &stream) = 0;

        [[nodiscard]] virtual std::unique_ptr<Level>
        parse_level(std::istream &stream) override;

        [[nodiscard]] virtual std::unique_ptr<std::istream>
        resolve_stream(const std::string &resource_identifier) override;

    public:
        using ParserService::ParserService;
    };
} // namespace dook
