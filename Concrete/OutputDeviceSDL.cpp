//
// Created by jon on 16/09/2019.
//

#include "OutputDeviceSDL.h"
#include "../Base/InstrumentBase.h"
#include <iostream>
#include <cassert>

#include "../Lib/WaveMath.h"


// userdata: this is the metadata that the user can specify to track the program's state between callback calls
// stream: this is the array that the audio device will read from and that we are supposed to write to here.
// streamLength: This is the length of the buffer that the device will play from before calling the callback again.
// I think streamLength is equal to the specified number of samples in the audio buffer, multiplied by the size, in
// bytes, of the sample type specified by the audio format.
void audioCallbackSDL(void* userData, Uint8* stream, int streamLength) {
    auto outputDeviceSDL = reinterpret_cast<OutputDeviceSDL*>(userData);
    auto * buffer = reinterpret_cast<SampleType*>(stream);
    auto bufferLen = streamLength / sizeof(SampleType);

//    for(uint32_t i = 0; i < bufferLen; ++i) {
//        buffer[i] = 0;
//    }

//    WaveMath::writeSine<SampleType>(buffer, streamLength, outputDeviceSDL->getSampleRate(),
//            440, outputDeviceSDL->_sampleCounter);

    for(InstrumentBase* instrument: outputDeviceSDL->_connectedInstruments) {
        if(instrument) {
            assert(instrument->getPrivateBuffer().size() == bufferLen);
            const auto& instrumentBuffer = instrument->getPrivateBuffer();
            for(uint32_t i = 0; i < bufferLen; ++i) {
                buffer[i] = instrumentBuffer[i];   // TODO: Normalize in some way to prevent clipping?
            }
            instrument->setBufferDirty();
        }
    }

    outputDeviceSDL->_sampleCounter += bufferLen;
}


OutputDeviceSDL::OutputDeviceSDL() {
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_AudioSpec desiredAudioSpec;

    desiredAudioSpec.callback = audioCallbackSDL;

    // userdata is a void pointer, allowing the user to keep track of some state
    // that is required inside the callback
    desiredAudioSpec.userdata = this;

    // This dictates the size of the audio buffer, in samples.
    // The smaller this is, the more often the callback will be called.
    desiredAudioSpec.samples = 256;
    // The approximate time between callback calls will be SDL_AudioSpec::samples / sample_rate

    desiredAudioSpec.freq = 44100;

    // TODO: static assert that sample type is signed 32 bit int
    desiredAudioSpec.format = AUDIO_S32LSB;

    desiredAudioSpec.channels = 1;

    _device = SDL_OpenAudioDevice(nullptr, 0, &desiredAudioSpec, &_obtainedAudioSpec, SDL_AUDIO_ALLOW_ANY_CHANGE);

    if(_device == 0) {
        std::cerr << "Error: " << SDL_GetError() << std::endl;
    }

    SDL_PauseAudioDevice(_device, 0);
}



OutputDeviceSDL::~OutputDeviceSDL() {
    SDL_CloseAudioDevice(_device);
    SDL_Quit();
}



OutputDeviceSDL &OutputDeviceSDL::get() {
    static OutputDeviceSDL instance{};
    return instance;
}


uint32_t OutputDeviceSDL::getSampleRate() {
    return _obtainedAudioSpec.freq;
}


uint32_t OutputDeviceSDL::getBufferSizeInSamples() {
    return _obtainedAudioSpec.samples;
}


void OutputDeviceSDL::connectTo(InstrumentBase *instrument) {
    _connectedInstruments.push_back(instrument);
}

uint32_t OutputDeviceSDL::startSampleOfPendingBuffer() const {
    return _sampleCounter;
}
