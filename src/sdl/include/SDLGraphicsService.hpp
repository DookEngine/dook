#pragma once
#include <GraphicsService.hpp>

namespace dook
{
    /**
     * @brief Implement graphics using the SDL2 library.
     *
     */
    class SDLGraphicsService : public GraphicsService
    {
    protected:
        virtual void draw() override;

    public:
        using GraphicsService::GraphicsService;
        ~SDLGraphicsService() = default;
        virtual std::unique_ptr<Texture> load_texture(std::string filename) override;
    };
}
