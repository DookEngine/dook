#pragma once
#include <Texture.hpp>

namespace dook
{
    class NullTexture final : Texture
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
        virtual bool load() override
        {
            this->_loaded = true;
            return true;
        };

        virtual bool loaded() const override
        {
            return this->_loaded;
        };

        virtual void *raw() const override
        {
            return nullptr;
        };
    };
};
