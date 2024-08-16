#ifndef NRF24L01_H
#define NRF24L01_H

#include "SPI_Interface.h"

#define NRF24L01_WRITE_REG   0x20
#define NRF24L01_READ_REG    0x00
#define NRF24L01_EN_RXADDR   0x02
#define NRF24L01_RX_PW_P0    0x11
#define NRF24L01_STATUS      0x07
#define NRF24L01_R_RX_PAYLOAD 0x61

class NRF24L01 {
private:
    SPI_Interface* spi;
    void writeRegister(uint8_t reg, uint8_t value);
    uint8_t readRegister(uint8_t reg);

public:
    NRF24L01(SPI_Interface* spi);
    void init();
    void setRxPipe(uint8_t pipe, uint8_t* address, uint8_t address_len, uint8_t payload_size);
    uint8_t readPayload(uint8_t* buffer, uint8_t length);
    uint8_t getStatus();
    uint8_t getRxPipeNumber();
};

#endif // NRF24L01_H
