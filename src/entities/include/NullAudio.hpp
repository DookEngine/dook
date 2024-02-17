#pragma once
#include <Audio.hpp>

namespace dook
{
    class NullAudio : Audio
    {
    private:
        bool _loaded;

    public:
        NullAudio(std::string file_name) : Audio(file_name), _loaded(false){};
        virtual void load() override
        {
            this->_loaded = true;
        };
        virtual bool loaded() override
        {
            return this->_loaded;
        };
        virtual void *raw_audio() override
        {
            return nullptr;
        };
    };
};
