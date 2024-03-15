#pragma once
#include <memory>
#include <InputService.hpp>

namespace dook
{
    /**
     * @brief Null placeholder for input generation.
     */
    class NullInputService final : public InputService
    {
    public:
        NullInputService() = default;

        virtual std::unique_ptr<Command> tick() override;
        virtual bool quit() override;
        virtual ~NullInputService() = default;
    };
}
