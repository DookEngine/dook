#pragma once
#include <InputService.hpp>
#ifdef CANCEL_SDL_MAIN
// SDL apperantly brings its own main function
// which causes a problem on windows, we pass
// -DCANCEL_SDL_MAIN on windows to trigger this
// which stops SDL from passing its own main.
// as per https://stackoverflow.com/a/25089610/6663851
#define SDL_MAIN_HANDLED
#endif // CANCEL_SDL_MAIN
#include <SDL.h>

namespace dook
{
    class SDLInputService : public InputService
    {
    private:
        bool _quit;

        /**
         * @brief Process a SDL keyboard event.
         *
         * Process SDL events related to keyboard input and return the corresponding command.
         *
         * @param event Event to process.
         * @return std::unique_ptr<dook::Command> Issued command or nullptr if not applicable.
         */
        std::unique_ptr<dook::Command> process_keyboard_event(SDL_Event &event);

        /**
         * @brief Process a SDL window event.
         *
         * Process any SDL events related to window actions and return the corresponding command.
         * @param event Event to process.
         * @return std::unique_ptr<dook::Command> Issued command or nullptr if not applicable.
         */
        std::unique_ptr<dook::Command> process_window_event(SDL_Event &event);

        /**
         * @brief Process a SDL event.
         *
         * Process any SDL events and return the corresponding command.
         * @param event Event to process.
         * @return std::unique_ptr<dook::Command> Issued command or nullptr if not applicable.
         */
        std::unique_ptr<dook::Command> process_event(SDL_Event &event);

    public:
        SDLInputService() : _quit(false){};

        virtual std::unique_ptr<Command> tick() override;
        virtual bool quit() override;
        virtual ~SDLInputService() = default;
    };
};