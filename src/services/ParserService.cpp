#include <ParserService.hpp>

const dook::EntityBundle &
dook::ParserService::load_manifest(std::string resource_identifier)
{
    auto istream = this->resolve_stream(resource_identifier);
    return this->parse_manifest(std::move(istream));
}

const dook::EntityBundle &
dook::ParserService::entity_bundle() const
{
    return *this->_entity_bundle;
}

[[nodiscard]] std::shared_ptr<dook::Level>
dook::ParserService::switch_level(std::string level_id)
{
    return this->load_level(level_id);
}