#include <Camera.hpp>

dook::Rect dook::Camera::safezone() const
{
    return {
        this->position().x + this->safezone_size().x / 2,
        this->position().y + this->safezone_size().y / 2,
        this->safezone_size().x,
        this->safezone_size().y};
}

dook::Rect dook::Camera::viewport() const
{
    return {
        this->position().x,
        this->position().y,
        this->size().x,
        this->size().y};
}

const dook::Vector<float> &dook::Camera::position() const
{
    return this->_position;
}

const dook::Vector<float> &dook::Camera::size() const
{
    return this->_size;
}

const dook::Vector<float> &dook::Camera::safezone_size() const
{
    return this->_safezone_size;
}

bool dook::Camera::contains(const Vector<float> &point) const
{
    return this->viewport().contains(point.x, point.y);
}

bool dook::Camera::safezone_contains(const Vector<float> &point) const
{
    return this->safezone().contains(point.x, point.y);
}

void dook::Camera::move(const Vector<float> &move_by)
{
    this->_position.x + move_by.x;
    this->_position.y + move_by.y;
}
