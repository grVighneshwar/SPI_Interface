#ifndef AVR_SPI_H
#define AVR_SPI_H

#include <SPI.h>
#include "SPI_Interface.h"

class AVR_SPI : public SPI_Interface {
public:
    void init() override;
    uint8_t transfer(uint8_t data) override;
    void setCS(bool state) override;
};

#endif // AVR_SPI_H
