//
// Created by jon on 18/09/2019.
//

#include <iostream>
#include <algorithm>
#include "SineOrgan.h"
#include "../Lib/WaveMath.h"


SineOrgan::SineOrgan(int numKeys) {
    _keyStates = std::vector<bool>(numKeys, false);
}


double SineOrgan::freqOfKey(int key) const {
    return _baseFrequency + key * _baseFrequency * 1.5;
}


void SineOrgan::updateBufferDerived(unsigned int startSample) {
    std::fill(_privateBuffer.begin(), _privateBuffer.end(), 0);

    // TODO: Placeholder just plays tone if any key is pressed.
    for(int i = 0; i < _keyStates.size(); ++i) {
        if(_keyStates[i]) {
            const auto freq = freqOfKey(i);
            WaveMath::addSine(_privateBuffer.data(), _privateBuffer.size(),
                    getSampleRate(),freq, std::numeric_limits<SampleType>::max() / _maxNotes, startSample);
        }
    }
}


bool SineOrgan::pressKey(int key) {
    if(key >= 0  &&  key < _keyStates.size()) {
        _keyStates[key] = true;
        return true;
    }
    return false;
}


bool SineOrgan::releaseKey(int key) {
    if(key >= 0  &&  key < _keyStates.size()) {
        _keyStates[key] = false;
        return true;
    }
    return false;
}

