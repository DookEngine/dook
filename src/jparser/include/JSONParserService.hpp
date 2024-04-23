#pragma once
#include <ParserService.hpp>
#include <Character.hpp>
#include <memory>
#include <nlohmann/json.hpp>

namespace dook
{
   /**
    * @brief Parser service used specifically to handle JSON to Level.
    *
    */
   class JSONParserService : public ParserService
   {
   private:
      /**
       * @brief Parse an individual character and return a
       * unique_ptr to it.
       *
       * @param json_object parsed json object.
       * @return std::unique_ptr<Character> Unique ptr to the character.
       */
      [[nodiscard]] std::shared_ptr<Character>
      parse_character(nlohmann::json json_object);

   protected:
      [[nodiscard]] virtual std::unique_ptr<EntityBundle> parse_entites(std::istream &stream) = 0;

      [[nodiscard]] virtual std::unique_ptr<Level>
      parse_level(std::istream &stream) override;

      [[nodiscard]] virtual std::unique_ptr<std::istream>
      resolve_stream(const std::string &resource_identifier) override;

   public:
      using ParserService::ParserService;
   };
} // namespace dook
