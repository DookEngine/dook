#include <ParserService.hpp>

std::unique_ptr<dook::Level>
dook::ParserService::parse_level(std::string resource_identifier)
{
    auto istream = this->resolve_stream(resource_identifier);
    return this->parse_level(*istream);
}
