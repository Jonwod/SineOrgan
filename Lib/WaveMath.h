//
// Created by jon on 14/09/2019.
//

#ifndef WAVEMATH_H
#define WAVEMATH_H
#include <cmath>
#include <limits>

namespace WaveMath {
    constexpr float pi = 3.14159265358979323846f;

    template<typename SAMPLE_TYPE>
    void writeSine(void* audioBuffer_Raw,
            uint32_t bufferBytes,
            uint32_t sampleRate,
            double cyclesPerSec,
            uint32_t startSample = 0)   // Can be used to offset the phase of the sine wave
    {
        const uint32_t numSamples = bufferBytes / sizeof(SAMPLE_TYPE);
        auto * audioBuffer = reinterpret_cast<SAMPLE_TYPE*>(audioBuffer_Raw);
        const double cyclesPerSample = cyclesPerSec / static_cast<double>(sampleRate);
        const double factor = cyclesPerSample * 2 * pi; // Not particularly sure what to call this constant
        const double phaseOffset = factor * startSample;
        for(uint32_t i = 0; i < numSamples; ++i) {
            const double normal = sin(i * factor + phaseOffset);
            audioBuffer[i] = normal * static_cast<double>(std::numeric_limits<SAMPLE_TYPE>::max());
        }
    }
}

#endif //WAVEMATH_H
