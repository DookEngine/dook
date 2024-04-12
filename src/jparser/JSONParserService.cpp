#include <JSONParserService.hpp>

[[nodiscard]] std::unique_ptr<dook::Level>
dook::JSONParserService::parse_level(const std::istream &)
{
    return nullptr;
}

[[nodiscard]] std::unique_ptr<std::istream>
dook::JSONParserService::resolve_stream(const std::string &)
{
    return nullptr;
}
