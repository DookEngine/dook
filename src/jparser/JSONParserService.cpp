#include <JSONParserService.hpp>
#include <nlohmann/json.hpp>
#include <fstream>

using json = nlohmann::json;

[[nodiscard]] std::unique_ptr<dook::Level>
dook::JSONParserService::parse_level(std::istream &stream)
{
    auto parsed_data = json::parse(stream);
    return nullptr;
}

[[nodiscard]] std::unique_ptr<std::istream>
dook::JSONParserService::resolve_stream(const std::string &resource_identifier)
{
    return std::make_unique<std::ifstream>(resource_identifier);
}
