//
// Created by jon on 18/09/2019.
//

#include <iostream>
#include "SineOrgan.h"
#include "../Lib/WaveMath.h"


void SineOrgan::update_buffer(unsigned int startSample) {
    WaveMath::writeSine<SampleType>(_privateBuffer.data(), _privateBuffer.size() * sizeof(SampleType),
            getSampleRate(),440, startSample);
}
