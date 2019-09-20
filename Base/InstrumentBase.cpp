//
// Created by jon on 16/09/2019.
//

#include "InstrumentBase.h"
#include <chrono>
#include <thread>

void InstrumentBase::run() {
    while(_connectedOutputDevice) {
        if(_bufferDirty) {
            update_buffer(_connectedOutputDevice->startSampleOfPendingBuffer());
            _bufferDirty = false;
        }
        else {
            std::this_thread::sleep_for(std::chrono::microseconds(200));
        }
    }
}
