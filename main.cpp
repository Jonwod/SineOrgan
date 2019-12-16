#include <iostream>
#include "SDL2/SDL.h"
#include "Concrete/SineOrgan.h"
#include "Concrete/OutputDeviceSDL.h"
#include "Concrete/InputDeviceSDL.h"

int main() {
    SineOrgan organ;
    organ.connectTo(&OutputDeviceSDL::get());

    // Update instrument(s)
    bool running = true;
    while(running) {
        // TODO: Fix crash:
        /* /Concrete/OutputDeviceSDL.cpp:32: void audioCallbackSDL(void*, Uint8*, int): Assertion `instrument->getPrivateBuffer().size() == bufferLen' failed.
            Aborted (core dumped) */

        if(InputDeviceSDL::get().isEscPressed())
            running = false;

        if(organ.isBufferDirty()) {
            for(int i = 0; i < organ.numKeys(); ++i) {
                // TODO: this should probably be using events
                if(InputDeviceSDL::get().isKeyPressed(i)) {
                    organ.pressKey(i);
                }
                else {
                    organ.releaseKey(i);
                }
            }

            organ.update_buffer();
        }
    }

    return 0;
}
