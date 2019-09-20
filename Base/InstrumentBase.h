//
// Created by jon on 16/09/2019.
//

#ifndef SINEORGAN_INSTRUMENTBASE_H
#define SINEORGAN_INSTRUMENTBASE_H

#include <vector>

#include "../Interface/OutputDeviceInterface.h"

/*
 * Subclasses should:
 *      - Update _privateBuffer as soon as possible after _bufferDirty is set to true, then set _bufferDirty to false
 */
class InstrumentBase {
public:
    void connectTo(OutputDeviceInterface * outputDevice) {
        if(!outputDevice)
            return;
        outputDevice->connectTo(this);

        _sampleRate = outputDevice->getSampleRate();
        _privateBuffer = std::vector<SampleType>(outputDevice->getBufferSizeInSamples(), SilentSample);

        _connectedOutputDevice = outputDevice;
    }

    // Other modules can look at the private buffer, but not mutate it.
    const std::vector<SampleType>& getPrivateBuffer() const { return _privateBuffer; };

    inline void setBufferDirty() { _bufferDirty = true; };
    inline bool isBufferDirty() { return _bufferDirty; };

    void update_buffer();
protected:
    // Subclass should implement this to write what it wants to the buffer
    virtual void updateBufferDerived(uint32_t startSample) = 0;

    inline uint32_t getSampleRate() const {return _sampleRate;}
    std::vector<SampleType> _privateBuffer;
private:
    uint32_t _sampleRate = 0;
    bool _bufferDirty = true;
    const OutputDeviceInterface* _connectedOutputDevice = nullptr;
};


#endif //SINEORGAN_INSTRUMENTBASE_H
