#pragma once
#include <GraphicsService.hpp>
#include <NullTexture.hpp>

namespace dook
{
    /**
     * @brief Noop graphics service.
     *
     */
    class NullGraphicsService : public GraphicsService
    {
    protected:
        virtual void draw() override { return; }

    public:
        virtual std::unique_ptr<Texture> load_texture(std::string file_name) override
        {
            return std::make_unique<NullTexture>(file_name);
        }
        virtual std::unique_ptr<Texture> load_texture(std::string file_name, const Rect &) override
        {
            return this->load_texture(file_name);
        }
        NullGraphicsService() : GraphicsService() {}
        NullGraphicsService(Camera viewport) : GraphicsService(viewport) {}
        ~NullGraphicsService() = default;
    };
}
