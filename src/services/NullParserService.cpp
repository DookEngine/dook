#include <NullParserService.hpp>
#include <sstream>

[[nodiscard]] std::unique_ptr<dook::Level>
dook::NullParserService::parse_level(std::istream &)
{
    return nullptr;
}

[[nodiscard]] std::unique_ptr<std::istream>
dook::NullParserService::resolve_stream(const std::string &resource_identifier)
{
    auto sstream = std::make_unique<std::stringstream>();
    *sstream << resource_identifier;
    return sstream;
}
