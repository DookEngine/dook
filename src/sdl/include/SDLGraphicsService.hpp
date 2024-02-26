#pragma once
#ifdef CANCEL_SDL_MAIN
// SDL apperantly brings its own main function
// which causes a problem on windows, we pass
// -DCANCEL_SDL_MAIN on windows to trigger this
// which stops SDL from passing its own main.
// as per https://stackoverflow.com/a/25089610/6663851
#define SDL_MAIN_HANDLED
#endif // CANCEL_SDL_MAIN
#include <SDL.h>
#include <GraphicsService.hpp>

namespace dook
{
    /**
     * @brief Implement graphics using the SDL2 library.
     *
     */
    class SDLGraphicsService : public GraphicsService
    {
    private:
        SDL_Window *window;
        SDL_Renderer *renderer;

    protected:
        virtual void draw() override;

    public:
        /**
         * @brief Construct a new SDLGraphicsService object
         *
         * Initializes and opens the window object as well.
         * @param screen_size
         */
        SDLGraphicsService(Rect screen_size);
        SDLGraphicsService() : SDLGraphicsService({0, 0, 1920, 1080}) {}

        /**
         * @brief Destroy the SDLGraphicsService object
         *
         * The associated renderer and the window is destroyed in this step.
         */
        ~SDLGraphicsService();
        virtual std::unique_ptr<Texture> load_texture(std::string filename) override;
    };
}
