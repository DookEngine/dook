#pragma once
#include <Texture.hpp>

namespace dook
{
    /**
     * @brief Empty texture object.
     *
     * Noop texture class to use for null service providers
     * or testing.
     */
    class NullTexture final : public Texture
    {
    private:
        bool _loaded;

    protected:
        virtual Rect texture_size() const override
        {
            return {0, 0, 0, 0};
        }

    public:
        NullTexture(std::string file_name) : Texture(file_name), _loaded(false){};
    };
};
