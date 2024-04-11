#pragma once
#include <memory>
#include <string>
#include <Rect.hpp>
#include <Texture.hpp>
#include <Camera.hpp>

namespace dook
{
    /**
     * @brief This service handles the drawing and rendering.
     */
    class GraphicsService
    {
    private:
        Camera _viewport;

    protected:
        /**
         * @brief Return a constant ref to current drawing obj.
         *
         * @return const Rect& Current drawing area.
         */
        const Camera &viewport() const;

        /**
         * @brief Return a reference to the currently drawn area.
         *
         * @return Rect& Reference to the drawn area.
         */
        Camera &viewport();

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
        GraphicsService(Camera viewport) : _viewport(viewport) {}

        GraphicsService() : GraphicsService(Camera{}) {}

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
         * @brief Load a texture into the memory with the given draw rect.
         *
         * @param filename Path to the texture.
         * @param draw_rect Draw rectangle information.
         * @return std::unique_ptr<Texture> Unique ptr to the texture.
         */
        virtual std::unique_ptr<Texture> load_texture(std::string filename, const Rect &draw_rect) = 0;

        /**
         * @brief Load a texture into memory from its filename.
         *
         * @param filename Filename to load from.
         * @return std::unique_ptr<Texture> Unique ptr to the texture.
         */
        virtual std::unique_ptr<Texture> load_texture(std::string filename) = 0;
    };
};
