//
// Created by jon on 18/09/2019.
//

#ifndef SINEORGAN_SINEORGAN_H
#define SINEORGAN_SINEORGAN_H

#include <vector>
#include <cmath>
#include "../Base/InstrumentBase.h"
#include "../Interface/OrganInterface.h"


// ~~~~~~~~ Frequency Functions ~~~~~~~~~~
double equalTemperament(unsigned int octaveDiv, double baseFreq, int note);

double equalTemperament12(int note);

double equalTemperament5(int note);

double equalTemperament7(int note);

double weirdFreqFunc1(int note);
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


class SineOrgan: public InstrumentBase, public OrganInterface {
public:
    explicit SineOrgan(int numKeys = 26);

    // ~~~~~~~~ OrganInterface ~~~~~~~~~~
    bool pressKey(int key) override;

    bool releaseKey(int key) override;
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    unsigned int numKeys() const override { return _keyStates.size();}

    // A frequency function takes an integer corresponding to a key and returns
    // a frequency
    typedef double (*FrequencyFunction)(int);
protected:
    void updateBufferDerived(unsigned int startSample) override;
private:
    FrequencyFunction _frequencyFunction = weirdFreqFunc1;

    std::vector<bool> _keyStates;
    const int _maxNotes = 5;
};

#endif //SINEORGAN_SINEORGAN_H
