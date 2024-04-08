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
#include <Texture.hpp>

namespace dook
{
    struct SDLSurfaceDeleter
    {
        void operator()(SDL_Surface *surface)
        {
            SDL_FreeSurface(surface);
        }
    };

    struct SDLTextureDeleter
    {
        void operator()(SDL_Texture *texture)
        {
            SDL_DestroyTexture(texture);
        }
    };

    class SDLTexture : public Texture
    {
    private:
        std::shared_ptr<SDL_Surface> _surface;
        std::shared_ptr<SDL_Texture> _texture;
        Rect _texture_size;

    protected:
        virtual Rect texture_size() const override;

    public:
        SDLTexture(SDL_Renderer *renderer, std::string filename, Rect draw_rect);
        SDLTexture(SDL_Renderer *renderer, std::string filename) : SDLTexture(renderer, filename, {0, 0, 0, 0}){};
        ~SDLTexture() = default;
        /**
         * @brief Set the texture size object
         *
         * To the given value.
         */
        void set_texture_size(Rect rect);

        /**
         * @brief Return the underlying texture object in GPU memory.
         *
         * @return SDL_Texture
         */
        std::shared_ptr<SDL_Texture> texture();

        /**
         * @brief Return the underlying surface object in CPU memory.
         *
         * @return SDL_Surface
         */
        std::shared_ptr<SDL_Surface> surface();

        /**
         * @brief Get the draw rectangle as an SDL rectangle.
         *
         * @return SDL_Rect Value of the SDL_Rectangle
         */
        SDL_Rect draw_rect_as_sdl() const;
    };
};
