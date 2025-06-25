uint16_t SPI_ReadRegister16(uint8_t reg_addr) {
    uint8_t cmd = reg_addr | 0xC0;  // Leitura + multibyte
    uint8_t rx_data[2] = {0};

    SPI_CS_LOW();
    SPI_Transmit(&cmd, 1);         // Envia comando (1 byte)
    SPI_Receive(rx_data, 2);       // Lê 2 bytes: MSB, LSB
    SPI_CS_HIGH();

    return ((uint16_t)rx_data[0] << 8) | rx_data[1];
}
