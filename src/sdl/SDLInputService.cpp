#include <SDLInputService.hpp>
#include <ServiceLocator.hpp>

std::unique_ptr<dook::Command> dook::SDLInputService::process_keyboard_event(SDL_Event &event)
{
    auto keycode = event.key.keysym.sym;
    switch (keycode)
    {
    case SDLK_ESCAPE:
        ServiceLocator::logger().log("user pressed escape.");
        this->_quit = true;
    default:
        return nullptr;
    }
}

std::unique_ptr<dook::Command> dook::SDLInputService::process_window_event(SDL_Event &event)
{
    auto event_name = event.window.event;
    switch (event_name)
    {
    case SDL_WINDOWEVENT_CLOSE:
        ServiceLocator::logger().log("user close window request.");
        this->_quit = true;
    default:
        return nullptr;
    }
}

std::unique_ptr<dook::Command> dook::SDLInputService::process_event(SDL_Event &event)
{
    switch (event.type)
    {
    case SDL_WINDOWEVENT:
        return this->process_event(event);
    case SDL_KEYDOWN:
        return this->process_event(event);
    default:
        return nullptr;
    }
}

std::unique_ptr<dook::Command> dook::SDLInputService::tick()
{
    SDL_Event event;
    std::unique_ptr<dook::Command> command;
    while (!this->quit())
    {
        while (SDL_PollEvent(&event))
        {
            command = this->process_event(event);
        }
    }
    return command;
}

bool dook::SDLInputService::quit()
{
    ServiceLocator::logger().log("Quitting input service.");
    return this->_quit;
}
