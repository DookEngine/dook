#include <Rect.hpp>
#include <iostream>
#include <Level.hpp>
#include <assert.h>
#include <Character.hpp>
#include <State.hpp>
#include <AIType.hpp>
#include <CharacterStates.hpp>
#include <CharacterStats.hpp>
#include <Position.hpp>
#include <NullTexture.hpp>
#include <NullAudio.hpp>

int main()
{
    auto bg = std::make_unique<dook::NullTexture>(std::string{"file.png"});
    auto fg = std::make_unique<dook::NullTexture>(std::string{"file.png"});
    auto ps = std::make_unique<dook::NullTexture>(std::string{"file.png"});
    dook::State state("standard");
    dook::CharacterStates states{state, state, state, state, state, state};
    dook::CharacterStats stats{
        dook::AIType::CONTROLLED,
        10,
        10,
        5,
        5,
        5,
        0.5,
        2};
    dook::Position position{0, 0};
    auto protogonist = std::make_shared<dook::Character>(
        std::string{"main_character"},
        stats,
        states,
        position);
    // Generate empty level.
    dook::Level level(
        std::string{"Sample"},
        std::move(bg),
        std::move(fg),
        std::move(ps));
    level.register_character(protogonist);
    auto prot = level.main_character();
    assert(prot == protogonist);
    prot->position().x += 5;
    assert(prot->position().x == 5);
    std::cout << prot->name() << std::endl;
}