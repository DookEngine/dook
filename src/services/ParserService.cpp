#include <ParserService.hpp>

std::unique_ptr<dook::Level>
dook::ParserService::load_manifest(std::string resource_identifier)
{
    auto istream = this->resolve_stream(resource_identifier);
    return this->parse_manifest(*istream);
}

const dook::EntityBundle &
dook::ParserService::entity_bundle() const
{
    return *this->_entity_bundle;
}