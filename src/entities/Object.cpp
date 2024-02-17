#include <Object.hpp>

/**
 * @brief Execute a command.
 */
bool dook::Object::set_state(const dook::State &target_state)
{
    if (this->current_state == this->terminal_state || this->textures.contains(target_state))
    {
        // Don't let escape from terminal state.
        // or switch to invalid state.
        return false;
    }
    Texture &old_texture = this->texture();
    old_texture.reset();
    // TODO: Check if this could cause a problem if target_state ref
    // is deleted by the parent closure?
    this->current_state = target_state;
    return true;
}

/**
 * @brief Execute a command.
 */
bool dook::Object::execute(const dook::Command &command)
{
    const auto target_state = command.to();
    return this->set_state(target_state);
}

bool dook::Object::can_remove() const
{
    return (this->terminal_state == this->current_state) && this->texture().is_animation_completed();
}

const dook::Texture &dook::Object::texture() const
{
    const dook::Texture &texture = *this->textures.at(this->current_state);
    return texture;
};

dook::Texture &dook::Object::texture()
{
    dook::Texture &texture = *this->textures.at(this->current_state);
    return texture;
};

const dook::State &dook::Object::state() const
{
    return this->current_state;
};

void dook::Object::reset()
{
    this->current_state = this->base_state;
}

bool dook::Object::at_base_state()
{
    return this->base_state == this->state();
}

void dook::Object::tick()
{
    this->texture().animate();
    // If the animation for the current state is completed
    // return to base state.
    if (!(this->at_base_state() || this->can_remove()) && this->texture().is_animation_completed())
    {
        this->reset();
    }
}

dook::Position &dook::Object::position()
{
    return this->_position;
}
