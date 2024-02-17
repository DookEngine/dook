#include <Character.hpp>

void dook::Character::tick()
{
    // Tick as an object first.
    Object::tick();
    // Then...
    // Heal if appliable.
    if (this->ticks_since_last_damage >= 10 && this->stats().health < this->stats().max_health)
    {
        // Either fill it up or just go towards that.
        const auto new_health = this->stats().health + this->stats().health_recovery_per_tick;
        this->mut_stats().health = new_health >= this->stats().max_health ? this->stats().max_health : new_health;
    }
    this->ticks_since_last_damage++;
}

void dook::Character::hurt(float damage)
{
    const auto next_health = this->stats().health - damage;
    if (next_health <= 0)
    {
        // Set health to zero and kill.
        this->mut_stats().health = 0;
        this->set_state(this->states().dead);
    }
    else
    {
        // Otherwise actually decrement health and set to hurting,
        // this will reset the hurting animation if it was already
        // playing.
        this->mut_stats().health = next_health;
        this->set_state(this->states().hurting);
    }
}