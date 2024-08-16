#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

#include <stdint.h>  // Include this for uint8_t
// #include <Arduino.h>  // Alternative if using Arduino

class SPI_Interface {
public:
    virtual void init() = 0;
    virtual uint8_t transfer(uint8_t data) = 0;
    virtual void setCS(bool state) = 0;
};

#endif // SPI_INTERFACE_H
