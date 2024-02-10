#pragma once
#include <string>

namespace dook
{
    /**
     * @brief Holds debug info about a src file.
     *
     * Used to hold which file and line pair a specific
     * resource originates from.
     */
    struct SourceInfo
    {
        std::string file_path;
        int line;
    };
};