#pragma once
#include <string>
#include <cstdlib>
#include <EntityType.hpp>
#include <SourceInfo.hpp>
namespace dook
{
    class Entity
    {
    private:
        std::string _name;
        SourceInfo _source;
        EntityType _type;
        int _id;

    public:
        /**
         * @brief Location the entity parsed from.
         *
         * Return the originating filename and line.
         */
        const SourceInfo &source_info() const { return _source; }
        /**
         * @brief Get the type of the entity.
         */
        const EntityType &type() const { return _type; }
        int id() const { return _id; }
        const std::string name() const { return _name; }
        friend bool operator<(const Entity &left, const Entity &right) { return left._id < right._id; }
        friend bool operator==(const Entity &left, const Entity &right) { return left._id == right._id; }

        /**
         * @brief Construct a new Entity object
         *
         * @param name Name of the entity.
         * @param source Source file/call the entity. originates from.
         * @param type Type of the entity.
         */
        Entity(std::string name, EntityType type, SourceInfo source) : _name(name), _source(source), _type(type), _id(std::rand())
        {
        }
        Entity(std::string name, EntityType type) : Entity(name, type, {"", 0}) {}
        Entity() = delete;
        virtual ~Entity() = 0;
    };
};
