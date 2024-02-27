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
    class SDLTexture : public Texture
    {
    private:
        SDL_Surface *_surface;
        SDL_Texture *_texture;
        Rect _texture_size;

    protected:
        virtual Rect texture_size() const override;

    public:
        using Texture::Texture;
        ~SDLTexture();
        /**
         * @brief Set the texture size object
         *
         * To the given value.
         */
        void set_texture_size(Rect rect);

        /**
         * @brief Return the underlying texture object in GPU memory.
         *
         * @return SDL_Texture&
         */
        SDL_Texture *&texture();

        /**
         * @brief Return the underlying surface object in CPU memory.
         *
         * @return SDL_Surface&
         */
        SDL_Surface *&surface();
    };
};
