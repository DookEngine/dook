#pragma once
#include <LevelService.hpp>

namespace dook
{
    class NullLevelService : public LevelService
    {
    public:
        NullLevelService();
        virtual bool load_level(std::string name) override;
    };
}