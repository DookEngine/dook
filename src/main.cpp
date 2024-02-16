#include <Rect.hpp>
#include <iostream>
#include <Level.hpp>
#include <Texture.hpp>
#include <Audio.hpp>

struct Empty
{
};

class EmptyAudio final : public dook::Audio<Empty>
{
protected:
    void load_audio(std::function<std::shared_ptr<Empty>(std::string)> loader) override{};

public:
    EmptyAudio(std::string f) : dook::Audio<Empty>(f){};
    ~EmptyAudio() = default;
    Empty raw_audio() override
    {
        return {};
    }
};

class EmptyTexture final : public dook::Texture<Empty>
{
public:
    EmptyTexture(std::string s) : Texture<Empty>(s){};
    Empty raw_texture() const override
    {
        return {};
    }
    virtual bool load_texture(std::function<std::shared_ptr<Empty>(std::string)> loader) const override
    {
        return false;
    }

    virtual dook::Rect texture_size() const override
    {
        return {0, 0, 0, 0};
    }

    ~EmptyTexture() = default;
};

int main()
{
    auto bg = std::make_unique<EmptyTexture>(std::string{"file.png"});
    auto fg = std::make_unique<EmptyTexture>(std::string{"file.png"});
    auto ps = std::make_unique<EmptyTexture>(std::string{"file.png"});
    // Generate empty level.
    dook::Level<Empty, Empty> level(
        std::string{"Sample"},
        std::move(bg),
        std::move(fg),
        std::move(ps));
}