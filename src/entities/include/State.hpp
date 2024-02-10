#pragma once
#include <Entity.hpp>
#include <EntityType.hpp>
#include <SourceInfo.hpp>

namespace dook
{
    /**
     * @brief Reperesents states used in the object state machines.
     */
    class State : public Entity
    {
    public:
        State(std::string name, SourceInfo source) : Entity(name, EntityType::STATE, source) {}
        State(std::string name) : Entity(name, EntityType::STATE) {}
        ~State() = default;
    };
};
