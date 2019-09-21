//
// Created by jon on 18/09/2019.
//

#ifndef SINEORGAN_SINEORGAN_H
#define SINEORGAN_SINEORGAN_H

#include <vector>
#include "../Base/InstrumentBase.h"
#include "../Interface/OrganInterface.h"


class SineOrgan: public InstrumentBase, public OrganInterface {
public:
    explicit SineOrgan(int numKeys = 26);

    // ~~~~~~~~ OrganInterface ~~~~~~~~~~
    bool pressKey(int key) override;

    bool releaseKey(int key) override;
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    unsigned int numKeys() const override { return _keyStates.size();}
protected:
    void updateBufferDerived(unsigned int startSample) override;
private:
    std::vector<bool> _keyStates;
};

#endif //SINEORGAN_SINEORGAN_H
