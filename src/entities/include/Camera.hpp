#pragma once
#include <Vector.hpp>
#include <Rect.hpp>
namespace dook
{
    /**
     * @brief Describes a Camera object.
     */
    class Camera
    {
    private:
        Vector<float> _position;
        Vector<float> _size;
        /**
         * @brief This is the part where the character can move in.
         * without moving the camera itself,
         */
        Vector<float> _safezone_size;

    public:
        /**
         * @brief Construct a new Camera object
         *
         * @param position Position of the camera.
         * @param size Size of the complete viewport.
         * @param safezone_size Size of the safezone in which the character
         * can move without moving the camera.
         */
        Camera(
            Vector<float> position,
            Vector<float> size,
            Vector<float> safezone_size) : _position(position), _size(size), _safezone_size(safezone_size) {}

        /**
         * @brief Construct a new Camera object
         *
         * Defaults to a 600x600 safezone.
         *
         * @param position Position of the camera.
         * @param size Size of the complete viewport.
         */
        Camera(Vector<float> position, Vector<float> size) : Camera(position, size, {600, 600}) {}

        /**
         * @brief Construct a new Camera object
         *
         * Constructs a full hd viewport with a 600x600
         * safezone.
         */
        Camera() : Camera({0, 0}, {1920, 1080}) {}

        /**
         * @brief Get the viewport of the camera.
         *
         * Viewport denotes the regions visible to the camera
         * within the greater level.
         *
         * @return Rect Returns the zone as a rectangle.
         */
        Rect viewport() const;

        /**
         * @brief Get the safezone boundaries of the camera.
         *
         * @return Rect Rectangle to the safezone boundaries.
         */
        Rect safezone() const;

        /**
         * @brief Return the position of the camera.
         *
         * @return const Vector& const ref to the position vector.
         */
        const Vector<float> &position() const;

        /**
         * @brief Size of the camera viewport.
         *
         * @return const Vector& Reference to the viewport.
         */
        const Vector<float> &size() const;

        /**
         * @brief Size of the safezone.
         *
         * @return const Vector&
         */
        const Vector<float> &safezone_size() const;

        /**
         * @brief Check if camera contains the point.
         *
         * @param point Point to check if inside.
         * @return true
         * @return false
         */
        bool contains(const Vector<float> &point) const;

        /**
         * @brief Check if the safezone contains the point.
         *
         * @param point Point to check against.
         * @return true
         * @return false
         */
        bool safezone_contains(const Vector<float> &point) const;

        /**
         * @brief Move the camera by the given vector.
         *
         * @param move_by
         */
        void move(const Vector<float> &move_by);
    };
} // namespace dook
