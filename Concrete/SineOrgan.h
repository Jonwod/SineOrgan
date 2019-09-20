//
// Created by jon on 18/09/2019.
//

#ifndef SINEORGAN_SINEORGAN_H
#define SINEORGAN_SINEORGAN_H

#include "../Base/InstrumentBase.h"
#include "../Interface/OrganInterface.h"


class SineOrgan: public InstrumentBase, public OrganInterface {
public:
    // ~~~~~~~~ OrganInterface ~~~~~~~~~~
    bool pressKey(int key) override { _keyPressed = true; return true; };
    bool releaseKey(int key) override { _keyPressed = false; return true; };
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    void update_buffer(unsigned int startSample) override;
private:
    // Single key organ for testing
    bool _keyPressed = false;
};


#endif //SINEORGAN_SINEORGAN_H
