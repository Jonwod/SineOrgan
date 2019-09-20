#include "SDL2/SDL.h"
#include "Concrete/SineOrgan.h"
#include "Concrete/OutputDeviceSDL.h"

int main() {
    SineOrgan organ;
    organ.connectTo(&OutputDeviceSDL::get());

    // Update instrument(s)
    while(true) {
        if(organ.isBufferDirty()) {
            organ.update_buffer();
        }
    }

    return 0;
}
