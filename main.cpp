#include "CH32V_SPI.h"
// #include "AVR_SPI.h" // Uncomment for AVR/Arduino
#include "NRF24L01.h"

CH32V_SPI spi;
NRF24L01 nrf(&spi);

uint8_t pipe0_address[5] = {0xE7, 0xE7, 0xE7, 0xE7, 0xE7}; // Example address for pipe 0
uint8_t pipe1_address[5] = {0xC2, 0xC2, 0xC2, 0xC2, 0xC2}; // Example address for pipe 1

void setup() {
    nrf.init();
    nrf.setRxPipe(0, pipe0_address, 5, 32); // Set up pipe 0
    nrf.setRxPipe(1, pipe1_address, 5, 32); // Set up pipe 1
}

void loop() {
    uint8_t buffer[32];
    uint8_t pipe = nrf.getRxPipeNumber();
    
    if (pipe < 6) { // Valid pipe number
        nrf.readPayload(buffer, 32);
        // Process the received data
    }
}
