#include "NRF24L01.h"

NRF24L01::NRF24L01(SPI_Interface* spi) : spi(spi) {}

void NRF24L01::init() {
    spi->init();
    writeRegister(NRF24L01_EN_RXADDR, 0x03); // Enable pipes 0 and 1
}

void NRF24L01::setRxPipe(uint8_t pipe, uint8_t* address, uint8_t address_len, uint8_t payload_size) {
    uint8_t base_reg = 0x0A + pipe; // Address registers start at 0x0A for pipe 0
    for (uint8_t i = 0; i < address_len; i++) {
        writeRegister(base_reg + i, address[i]);
    }
    writeRegister(NRF24L01_RX_PW_P0 + pipe, payload_size); // Set payload size
}

uint8_t NRF24L01::readPayload(uint8_t* buffer, uint8_t length) {
    spi->setCS(false);
    spi->transfer(NRF24L01_R_RX_PAYLOAD);
    for (uint8_t i = 0; i < length; i++) {
        buffer[i] = spi->transfer(0xFF);
    }
    spi->setCS(true);
    return length;
}

uint8_t NRF24L01::getStatus() {
    return readRegister(NRF24L01_STATUS);
}

uint8_t NRF24L01::getRxPipeNumber() {
    uint8_t status = getStatus();
    return (status >> 1) & 0x07; // Extract pipe number
}

void NRF24L01::writeRegister(uint8_t reg, uint8_t value) {
    spi->setCS(false);
    spi->transfer(NRF24L01_WRITE_REG | reg);
    spi->transfer(value);
    spi->setCS(true);
}

uint8_t NRF24L01::readRegister(uint8_t reg) {
    spi->setCS(false);
    spi->transfer(NRF24L01_READ_REG | reg);
    uint8_t result = spi->transfer(0xFF);
    spi->setCS(true);
    return result;
}
