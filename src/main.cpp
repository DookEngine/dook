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
#include <ServiceLocator.hpp>
#include <NullAudio.hpp>

int main()
{
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
    auto level = dook::ServiceLocator<dook::NullTexture>::level().current_level();
    level->register_character(protogonist);
    auto prot = level->main_character();
    assert(prot == protogonist);
    prot->position().x += 5;
    assert(prot->position().x == 5);
    std::cout << prot->name() << std::endl;
}