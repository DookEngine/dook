#include <Texture.hpp>

template <class T>
bool dook::Texture<T>::is_draw_rect_last()
{
    if (!this->draw_rectangle())
    {
        // No draw rectangle means we are already at the last step,
        // since technically there are no steps.
        return true;
    }
    // Otherwise...
    auto draw_rect = this->draw_rectangle().value();
    bool is_touching_the_end_x = (draw_rect.x + draw_rect.w) >= (this->texture_size().w);
    bool is_touching_the_end_y = (draw_rect.y + draw_rect.h) >= (this->texture_size().h);
    return is_touching_the_end_x && is_touching_the_end_y;
}

template <class T>
void dook::Texture<T>::reset()
{
    if (this->_draw_rectangle.has_value())
    {
        this->_draw_rectangle.emplace({
            0,
            0,
            this->_draw_rectangle.value().w,
            this->_draw_rectangle.value().h,
        });
    }
}

template <class T>
void dook::Texture<T>::animate()
{
    if (this->_animation_step.has_value() && this->_draw_rectangle.has_value())
    {
        auto step = this->_animation_step.value();
        if (this->is_draw_rect_last())
        {
            // Reset the draw_rect to original position.
            this->reset();
        }
        else
        {
            // Otherwise, increment a step.
            this->_draw_rectangle.emplace(this->_draw_rectangle.value() + step);
        }
    }
}