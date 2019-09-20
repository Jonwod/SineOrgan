#include "SDL2/SDL.h"
#include "Concrete/SineOrgan.h"
#include "Concrete/OutputDeviceSDL.h"
#include "Concrete/InputDeviceSDL.h"

int main() {
    SineOrgan organ;
    organ.connectTo(&OutputDeviceSDL::get());

    // Update instrument(s)
    while(true) {
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
