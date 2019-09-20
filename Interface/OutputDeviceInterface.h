//
// Created by jon on 16/09/2019.
//

#ifndef SINEORGAN_OUTPUTDEVICEINTERFACE_H
#define SINEORGAN_OUTPUTDEVICEINTERFACE_H

#include <stdint-gcc.h>

// This cannot be dynamic so I have chosen for now to keep it here
typedef int32_t SampleType;
constexpr int32_t SilentSample = 0;

class InstrumentBase;

class OutputDeviceInterface {
public:
    virtual void connectTo(InstrumentBase *instrument) = 0;
    virtual uint32_t getSampleRate() = 0;
    virtual uint32_t getBufferSizeInSamples() = 0;
    // i.e. the number of samples played before the start of the current pending buffer
    virtual uint32_t startSampleOfPendingBuffer() const = 0;
};

#endif //SINEORGAN_OUTPUTDEVICEINTERFACE_H
