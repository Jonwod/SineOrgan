//
// Created by jon on 18/09/2019.
//

#include <iostream>
#include "SDL2/SDL.h"
#include "SineOrgan.h"
#include "../Lib/WaveMath.h"


SineOrgan::SineOrgan(int numKeys) {
    _keyStates = std::vector<bool>(numKeys, false);
}


void SineOrgan::updateBufferDerived(unsigned int startSample) {
    // TODO: Placeholder just plays tone if any key is pressed.
    for(bool pressed: _keyStates) {
        if(pressed) {
            WaveMath::writeSine<SampleType>(_privateBuffer.data(), _privateBuffer.size() * sizeof(SampleType),
                                            getSampleRate(),440, startSample);
            return;
        }
    }

    for(auto& elem: _privateBuffer) {
        elem = 0;
    }
}

