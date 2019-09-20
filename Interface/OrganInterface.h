//
// Created by jon on 15/09/2019.
//

#ifndef SINEORGAN_ORGANINTERFACE_H
#define SINEORGAN_ORGANINTERFACE_H

/*
 * Provides a public interface for using an organ
 */
class OrganInterface {
public:
    /* An organ will have keys associated with integers.
     These functions return true if the key exists or false otherwise.*/
    virtual bool pressKey(int key) = 0;
    virtual bool releaseKey(int key) = 0;

    virtual unsigned int numKeys() const = 0;
};

#endif //SINEORGAN_ORGANINTERFACE_H
