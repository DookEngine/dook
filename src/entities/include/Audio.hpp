#pragma once
#include <functional>
#include <memory>
#include <string>
namespace dook
{
    class Audio
    {
    private:
        std::string _file_name;

    public:
        virtual void load() = 0;
        virtual bool loaded() = 0;
        virtual void *raw_audio() = 0;

        /**
         * @brief Construct a new Audio object
         *
         * @param file_name Location of the audio file.
         */
        Audio(std::string file_name) : _file_name(file_name){};
        Audio() = delete;
    };
};
