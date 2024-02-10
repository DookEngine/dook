#pragma once
#include <string>
#include <optional>
#include <Rect.hpp>

namespace dook
{
    template <class T>
    class Texture
    {
    private:
        std::string file_name;
        /**
         * @brief Subsection of the texture to draw.
         */
        std::optional<Rect> _draw_rectangle;
        /**
         * @brief Iteration step for animating.
         */
        std::optional<Rect> _animation_step;

        T _raw_texture;

        /**
         * @brief Check if animation step is the last one.
         *
         * True if this is the final possible animation to draw.
         * @return true If the draw rectangle touches the end of the texture.
         * @return false otherwise.
         */
        bool is_draw_rect_last();

    protected:
        /**
         * @brief Get the size of the texure.
         */
        virtual Rect texture_size() const = 0;

        /**
         * @brief Initialise a texture from the file.
         *
         * @return true on success.
         * @return false on failure.
         */
        virtual bool load_texture() const = 0;

    public:
        Texture(std::string file_name) : file_name(file_name)
        {
        }
        Texture(std::string file_name, Rect draw_rectangle) : file_name(file_name), _draw_rectangle(draw_rectangle){};
        Texture(std::string file_name, Rect draw_rectangle, Rect animation_step) : file_name(file_name), _draw_rectangle(draw_rectangle), _animation_step(animation_step){};
        Texture() = delete;
        /**
         * @brief Take a step in animation.
         *
         * Loops back to texture resource.
         */
        void animate();

        /**
         * @brief Reset the animation
         */
        void reset();

        virtual T raw_texture() const = 0;
        /**
         * @brief Return currently active draw rectangle.
         */
        const std::optional<Rect> &draw_rectangle() const { return draw_rectangle; };

        virtual ~Texture() = 0;
    };
};
