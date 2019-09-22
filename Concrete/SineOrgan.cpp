//
// Created by jon on 18/09/2019.
//

#include <iostream>
#include <algorithm>
#include "SineOrgan.h"
#include "../Lib/WaveMath.h"


// ~~~~~~~~ Frequency Functions ~~~~~~~~~~
double equalTemperament(unsigned int octaveDiv, double baseFreq, int note) {
    // Possible optimization: this only needs to be calculated once for each temperament system. Perhaps a functor?
    const double intervalRatio = pow(2.0, 1.0/octaveDiv);

    return pow(intervalRatio, note) * baseFreq;
}


double equalTemperament12(int note) {
    return equalTemperament(12, 200.0, note);
}


double equalTemperament5(int note) {
    return equalTemperament(5, 120.0, note);
}

double equalTemperament7(int note) {
    return equalTemperament(7, 120.0, note);
}


double weirdFreqFunc1(int key) {
    const double baseFrequency = 40.0;
    return baseFrequency + key * baseFrequency * 1.5;
}
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~



SineOrgan::SineOrgan(int numKeys) {
    _keyStates = std::vector<bool>(numKeys, false);
}


void SineOrgan::updateBufferDerived(unsigned int startSample) {
    std::fill(_privateBuffer.begin(), _privateBuffer.end(), 0);

    // TODO: Placeholder just plays tone if any key is pressed.
    for(int i = 0; i < _keyStates.size(); ++i) {
        if(_keyStates[i]) {
            const auto freq = _frequencyFunction(i);
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

