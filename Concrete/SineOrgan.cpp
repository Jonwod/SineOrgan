//
// Created by jon on 18/09/2019.
//

#include <iostream>
#include "SDL2/SDL.h"
#include "SineOrgan.h"
#include "../Lib/WaveMath.h"



std::vector<int> getPressedKeys() {
    std::vector<int> pressedKeys;
    const Uint8 *keyboardState = SDL_GetKeyboardState(NULL);

    if (keyboardState[SDL_SCANCODE_Z]) {
        pressedKeys.push_back(0);
    }
    if (keyboardState[SDL_SCANCODE_X]) {
        pressedKeys.push_back(1);
    }
    if (keyboardState[SDL_SCANCODE_C]) {
        pressedKeys.push_back(2);
    }
    if (keyboardState[SDL_SCANCODE_V]) {
        pressedKeys.push_back(3);
    }
    if (keyboardState[SDL_SCANCODE_B]) {
        pressedKeys.push_back(4);
    }
    if (keyboardState[SDL_SCANCODE_N]) {
        pressedKeys.push_back(5);
    }
    if (keyboardState[SDL_SCANCODE_M]) {
        pressedKeys.push_back(6);
    }
    if (keyboardState[SDL_SCANCODE_A]) {
        pressedKeys.push_back(7);
    }
    if (keyboardState[SDL_SCANCODE_S]) {
        pressedKeys.push_back(8);
    }
    if (keyboardState[SDL_SCANCODE_D]) {
        pressedKeys.push_back(9);
    }
    if (keyboardState[SDL_SCANCODE_F]) {
        pressedKeys.push_back(10);
    }
    if (keyboardState[SDL_SCANCODE_G]) {
        pressedKeys.push_back(11);
    }
    if (keyboardState[SDL_SCANCODE_H]) {
        pressedKeys.push_back(12);
    }
    if (keyboardState[SDL_SCANCODE_J]) {
        pressedKeys.push_back(13);
    }
    if (keyboardState[SDL_SCANCODE_K]) {
        pressedKeys.push_back(14);
    }
    if (keyboardState[SDL_SCANCODE_L]) {
        pressedKeys.push_back(15);
    }
    if (keyboardState[SDL_SCANCODE_Q]) {
        pressedKeys.push_back(16);
    }
    if (keyboardState[SDL_SCANCODE_W]) {
        pressedKeys.push_back(17);
    }
    if (keyboardState[SDL_SCANCODE_E]) {
        pressedKeys.push_back(18);
    }
    if (keyboardState[SDL_SCANCODE_R]) {
        pressedKeys.push_back(19);
    }
    if (keyboardState[SDL_SCANCODE_T]) {
        pressedKeys.push_back(20);
    }
    if (keyboardState[SDL_SCANCODE_Y]) {
        pressedKeys.push_back(21);
    }
    if (keyboardState[SDL_SCANCODE_U]) {
        pressedKeys.push_back(22);
    }
    if (keyboardState[SDL_SCANCODE_I]) {
        pressedKeys.push_back(23);
    }
    if (keyboardState[SDL_SCANCODE_O]) {
        pressedKeys.push_back(24);
    }
    if (keyboardState[SDL_SCANCODE_P]) {
        pressedKeys.push_back(25);
    }

    return pressedKeys;
}


void SineOrgan::updateBufferDerived(unsigned int startSample) {
    if(getPressedKeys().empty()){
        WaveMath::writeSine<SampleType>(_privateBuffer.data(), _privateBuffer.size() * sizeof(SampleType),
                                        getSampleRate(),440, startSample);
    }
    else {
        for(auto& elem: _privateBuffer) {
            elem = 0;
        }
    }
}


void SineOrgan::onUpdate() {
    getPressedKeys();
}
