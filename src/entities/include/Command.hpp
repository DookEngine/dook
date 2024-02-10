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
        /** Commands may have a duration, after which the actee should revert to its base state.*/
        int _time_to_revert;
        const State &_to;

    public:
        Command(
            std::string name,
            const State &to,
            int time_to_revert,
            SourceInfo source)
            : Entity(name, EntityType::COMMAND, source),
              _time_to_revert(time_to_revert),
              _to(to) {}
        Command(std::string name, const State &to, int time_to_revert) : Command(name, to, time_to_revert, {"", 0}) {}
        Command(std::string name, const State &to) : Command(name, to, -1) {}
        ~Command() = default;

        int time_to_revert() const { return _time_to_revert; }
        const State &to() const { return _to; }
    };
};
