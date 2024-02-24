#include <memory>
#include <string>
#include <Rect.hpp>
#include <Texture.hpp>

namespace dook
{
    /**
     * @brief This service handles the drawing and rendering.
     */
    template <typename TextureType = Texture>
    class GraphicsService
    {
    private:
        Rect _viewport;

    protected:
        /**
         * @brief Return a constant ref to current drawing obj.
         *
         * @return const Rect& Current drawing area.
         */
        const Rect &viewport() const;

        /**
         * @brief Return a reference to the currently drawn area.
         *
         * @return Rect& Reference to the drawn area.
         */
        Rect &viewport();

        /**
         * @brief Draw the screen wrt to the draw rect.
         */
        virtual void draw() = 0;

    public:
        /**
         * @brief Construct a new Graphics Service object
         *
         * Constructs the window object as well.
         *
         * @param viewport the size of the "screen" and its offset
         * in the total texture.
         */
        GraphicsService(Rect viewport) : _viewport(viewport) {}

        GraphicsService() : GraphicsService({0, 0, 1920, 1080}) {}

        /**
         * @brief Destroy the Graphics Service object
         *
         * Deallocate the window resources as well.
         */
        virtual ~GraphicsService() = default;

        /**
         * @brief Re-draw the screen.
         */
        void tick();

        /**
         * @brief Load a texture into memory from its filename.
         *
         * @param filename Filename to load from.
         * @return std::unique_ptr<TextureType> Unique ptr to the texture.
         */
        virtual std::unique_ptr<TextureType> load_texture(std::string filename) = 0;
    };
};
