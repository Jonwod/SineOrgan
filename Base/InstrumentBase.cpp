//
// Created by jon on 16/09/2019.
//

#include "InstrumentBase.h"
#include <chrono>
#include <thread>


void InstrumentBase::update_buffer() {
    updateBufferDerived(_connectedOutputDevice ? _connectedOutputDevice->startSampleOfPendingBuffer(): 0);
    _bufferDirty = false;
}
