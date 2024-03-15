#include <NullInputService.hpp>

std::unique_ptr<dook::Command> dook::NullInputService::tick()
{
    return nullptr;
}

bool dook::NullInputService::quit()
{
    return false;
}
