#include <Object.hpp>

/**
 * @brief Execute a command.
 */
template <class T, class S>
bool dook::Object<T, S>::execute(const dook::Command &command)
{
    const auto target_state = command.to();
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
 * @brief Check if the object is in terminal state with completed anim.
 */
template <class T, class S>
bool dook::Object<T, S>::can_remove() const
{
    return false;
}

/**
 * @brief Get the current texture of the object.
 */
template <class T, class S>
dook::Texture<T> &dook::Object<T, S>::texture() const
{
    return this->textures[this->state];
};

/**
 * @brief Get the current state of the object.
 */
template <class T, class S>
const dook::State &dook::Object<T, S>::state() const
{
    return this->state;
};

/**
 * @brief Perform a tick on an object.
 */
template <class T, class S>
void dook::Object<T, S>::tick()
{
    this->texture().animate();
}