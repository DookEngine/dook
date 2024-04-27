#include <JSONParserService.hpp>
#include <fstream>
#include <memory>
#include <CharacterStats.hpp>
#include <CharacterStates.hpp>
#include <ServiceLocator.hpp>
#include <State.hpp>
#include <Position.hpp>

using json = nlohmann::json;

[[nodiscard]] std::shared_ptr<dook::Character>
dook::JSONParserService::parse_character(nlohmann::json json_object)
{
    CharacterStats stats;
    stats.max_health = json_object["stats"]["max_health"];
    stats.health = stats.max_health;
    State state("idle");
    CharacterStates states{
        state,
        state,
        state,
        state,
        state,
        state};
    std::string character_name(json_object["name"]);
    dook::Position position{0.0, 0.0};
    auto character_object = std::make_shared<Character>(character_name,
                                                        stats,
                                                        states,
                                                        position);
    auto character_texture = ServiceLocator::graphics().load_texture(json_object["states"]["idle"]["texture"]["path"]);
    character_object->set_texture_for_state(state, std::move(character_texture));
    return character_object;
}

[[nodiscard]] std::unique_ptr<dook::EntityBundle>
dook::JSONParserService::parse_entites(std::istream &stream)
{
    EntityBundle bundle;
    try
    {
        auto parsed_data = json::parse(stream);
        auto characters = parsed_data["characters"];
        for (auto character : characters)
        {
            auto character_object = this->parse_character(character);
            bundle.characters.push_back(character_object);
        }
    }
    catch (const std::exception &e)
    {
        ServiceLocator::logger().error("Invalid JSON manifest for the game.");
    }
}

std::unique_ptr<dook::Level>
dook::JSONParserService::load_level(std::string)
{
    return nullptr;
}

[[nodiscard]] std::unique_ptr<dook::Level> dook::JSONParserService::parse_manifest(std::istream &stream)
{
    auto parsed_data = json::parse(stream);
    return nullptr;
}

[[nodiscard]] std::unique_ptr<std::istream>
dook::JSONParserService::resolve_stream(const std::string &resource_identifier)
{
    return std::make_unique<std::ifstream>(resource_identifier);
}
