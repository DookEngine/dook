#pragma once
#include <functional>
#include <memory>
#include <string>
namespace dook
{
    template <class S>
    class Audio
    {
    private:
        std::shared_ptr<S> _raw_audio;
        std::string _file_name;

    protected:
        /**
         * @brief Load the audio file to memory.
         *
         * @param loader: Function to call with the filename to load the string.
         */
        virtual void load_audio(std::function<std::shared_ptr<S>(std::string)> loader) = 0;

    public:
        /**
         * @brief Construct a new Audio object
         *
         * @param file_name Location of the audio file.
         */
        Audio(std::string file_name) : _file_name(file_name){};
        Audio() = delete;

        /**
         * @brief Get the raw audio file.
         *
         * @return S
         */
        virtual S raw_audio() = 0;
    };
};
