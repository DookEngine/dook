#include <Object.hpp>

/**
 * @brief Execute a command.
 */
template <class T, class S>
bool dook::Object<T, S>::set_state(const dook::State &target_state)
{
    if (this->current_state == this->terminal_state || this->textures.contains(target_state))
    {
        // Don't let escape from terminal state.
        // or switch to invalid state.
        return false;
    }
    auto old_texture = this->texture();
    old_texture.reset();
    this->current_state = target_state;
    return true;
}

/**
 * @brief Execute a command.
 */
template <class T, class S>
bool dook::Object<T, S>::execute(const dook::Command &command)
{
    const auto target_state = command.to();
    return this->set_state(target_state);
}

template <class T, class S>
bool dook::Object<T, S>::can_remove() const
{
    return (this->terminal_state == this->current_state) && this->texture().is_animation_completed();
}

template <class T, class S>
dook::Texture<T> &dook::Object<T, S>::texture() const
{
    return this->textures[this->state];
};

template <class T, class S>
const dook::State &dook::Object<T, S>::state() const
{
    return this->state;
};

template <class T, class S>
void dook::Object<T, S>::reset()
{
    this->current_state = this->base_state;
}

template <class T, class S>
bool dook::Object<T, S>::at_base_state()
{
    return this->base_state == this->state();
}

template <class T, class S>
void dook::Object<T, S>::tick()
{
    this->texture().animate();
    // If the animation for the current state is completed
    // return to base state.
    if (!(this->at_base_state() || this->can_remove()) && this->texture().is_animation_complete())
    {
        this->reset();
    }
}