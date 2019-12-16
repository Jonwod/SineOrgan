//
// Created by jon on 16/09/2019.
//

#ifndef SINEORGAN_OUTPUTDEVICESDL_H
#define SINEORGAN_OUTPUTDEVICESDL_H

#include <vector>
#include "SDL2/SDL.h"   // This should be the only module in the project that uses SDL
#include "../Interface/OutputDeviceInterface.h"


class OutputDeviceSDL: public OutputDeviceInterface {
public:
    // ~~~~~~~~~~~~ Singleton ~~~~~~~~~~~~~~
    // Is a Singleton, as it is not possible for more than one to exist at a time anyway
    static OutputDeviceSDL & get();
    OutputDeviceSDL(const OutputDeviceSDL &) = delete;
    void operator=(const OutputDeviceSDL &) = delete;
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    ~OutputDeviceSDL();

    // ~~~~~~~~~ OutputDeviceInterface ~~~~~~
    void connectTo(InstrumentBase *instrument) override;
    uint32_t getSampleRate() override;
    uint32_t getBufferSizeInSamples() override;
    uint32_t startSampleOfPendingBuffer() const override;
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    // Stop the audio stream
    void stop();
private:
    OutputDeviceSDL();

    friend void audioCallbackSDL(void* userData, Uint8* stream, int streamLength);

    SDL_AudioSpec _obtainedAudioSpec;
    SDL_AudioDeviceID _device;
    uint32_t _sampleCounter = 0;
    std::vector<InstrumentBase*> _connectedInstruments;
};


#endif //SINEORGAN_OUTPUTDEVICESDL_H
