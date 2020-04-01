//
// Created by jon on 20/09/2019.
//

#ifndef SINEORGAN_INPUTDEVICESDL_H
#define SINEORGAN_INPUTDEVICESDL_H

#include <vector>

class InputDeviceSDL {
public:
    // ~~~~~~~~~~~~ Singleton ~~~~~~~~~~~~~~
    // Is a Singleton, as it is not possible for more than one to exist at a time anyway
    static InputDeviceSDL & get();
    InputDeviceSDL(const InputDeviceSDL &) = delete;
    void operator=(const InputDeviceSDL &) = delete;
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    bool isKeyPressed(int keyIndex) const;
    const std::vector<bool> getKeyPressedStates() const { return _keyPressedStates; };

    bool isEscPressed() const;
private:
    InputDeviceSDL();
    ~InputDeviceSDL();
    std::vector<bool> _keyPressedStates;
};


#endif //SINEORGAN_INPUTDEVICESDL_H
