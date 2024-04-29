#include <NullParserService.hpp>
#include <sstream>

[[nodiscard]] const dook::EntityBundle &
dook::NullParserService::parse_manifest(std::unique_ptr<std::istream>)
{
    return *this->_entity_bundle;
}

[[nodiscard]] const dook::EntityBundle &
dook::NullParserService::parse_entites(std::unique_ptr<std::istream>)
{
    return *this->_entity_bundle;
}

[[nodiscard]] std::unique_ptr<std::istream>
dook::NullParserService::resolve_stream(const std::string &resource_identifier)
{
    auto sstream = std::make_unique<std::stringstream>();
    *sstream << resource_identifier;
    return sstream;
}

[[nodiscard]] std::shared_ptr<dook::Level>
dook::NullParserService::load_level(std::string)
{
    return nullptr;
}
