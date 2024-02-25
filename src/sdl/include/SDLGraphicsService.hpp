#pragma once
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
