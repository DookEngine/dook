#include <GraphicsService.hpp>
#include <NullTexture.hpp>

namespace dook
{
    /**
     * @brief Noop graphics service.
     *
     */
    class NullGraphicsService : public GraphicsService<NullTexture>
    {
    protected:
        virtual void draw() override { return; }

    public:
        virtual std::unique_ptr<NullTexture> load_texture(std::string file_name) override
        {
            return std::make_unique<NullTexture>(file_name);
        }
        NullGraphicsService() : GraphicsService() {}
        NullGraphicsService(Rect rect) : GraphicsService(rect) {}
        ~NullGraphicsService() = default;
    };
}
