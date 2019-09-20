//
// Created by jon on 20/09/2019.
//

#include "InputDeviceSDL.h"
#include <vector>
#include <array>
#include "SDL2/SDL.h"



InputDeviceSDL &InputDeviceSDL::get() {
    static InputDeviceSDL instance{};
    return instance;
}


const std::array<SDL_Scancode, 26> keyCodes = {
        SDL_SCANCODE_Z,
        SDL_SCANCODE_X,
        SDL_SCANCODE_C,
        SDL_SCANCODE_V,
        SDL_SCANCODE_B,
        SDL_SCANCODE_N,
        SDL_SCANCODE_M,
        SDL_SCANCODE_A,
        SDL_SCANCODE_S,
        SDL_SCANCODE_D,
        SDL_SCANCODE_F,
        SDL_SCANCODE_G,
        SDL_SCANCODE_H,
        SDL_SCANCODE_J,
        SDL_SCANCODE_K,
        SDL_SCANCODE_L,
        SDL_SCANCODE_Q,
        SDL_SCANCODE_W,
        SDL_SCANCODE_E,
        SDL_SCANCODE_R,
        SDL_SCANCODE_T,
        SDL_SCANCODE_Y,
        SDL_SCANCODE_U,
        SDL_SCANCODE_I,
        SDL_SCANCODE_O,
        SDL_SCANCODE_P
};



InputDeviceSDL::InputDeviceSDL() {
    // Currently supporting 26 keys, but this needs to be kept up-to-date
    _keyPressedStates = std::vector<bool>(26, false);
}


bool InputDeviceSDL::isKeyPressed(int keyIndex) const {
    if(keyIndex >= keyCodes.size())
        return false;
    std::vector<int> pressedKeys;
    const Uint8 *keyboardState = SDL_GetKeyboardState(NULL);
    const SDL_Scancode SDLKey = keyCodes[keyIndex];
    return keyboardState[SDLKey];
}
