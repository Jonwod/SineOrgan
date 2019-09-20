#include "SDL2/SDL.h"
#include "Concrete/SineOrgan.h"
#include "Concrete/OutputDeviceSDL.h"

int main() {
    SineOrgan organ;
    organ.connectTo(&OutputDeviceSDL::get());
    organ.run();

    return 0;
}
