#pragma once
#include <Entity.hpp>
#include <EntityType.hpp>
#include <SourceInfo.hpp>
#include <State.hpp>

namespace dook
{
    /**
     * @brief Reperesents state switching commands used for objects.
     */
    class Command : public Entity
    {
    private:
        State _to;

    public:
        Command(
            std::string name,
            const State &to,
            SourceInfo source)
            : Entity(name, EntityType::COMMAND, source),
              _to(to) {}
        Command(std::string name, const State &to) : Command(name, to, {"", 0}) {}
        ~Command() = default;

        const State &to() const { return _to; }
    };
};
