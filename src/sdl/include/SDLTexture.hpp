#pragma once
#include <Texture.hpp>

namespace dook
{
    class SDLTexture : public Texture
    {
    private:
        Rect _texture_size;

    protected:
        virtual Rect texture_size() const override;

    public:
        using Texture::Texture;
        ~SDLTexture() = default;
        /**
         * @brief Set the texture size object
         *
         * To the given value.
         */
        void set_texture_size(Rect rect);
    };
};
