#ifndef CH32V_SPI_H
#define CH32V_SPI_H

#include <stdint.h>  // Include this for uint8_t
#include "SPI_Interface.h"
#include "ch32v00x.h"

class CH32V_SPI : public SPI_Interface {
public:
    void init() override;
    uint8_t transfer(uint8_t data) override;
    void setCS(bool state) override;
};

#endif // CH32V_SPI_H
