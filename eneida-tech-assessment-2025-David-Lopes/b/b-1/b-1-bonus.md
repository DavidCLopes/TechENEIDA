## Bónus – Leitura de Registo de 16 Bits via SPI

A leitura de registos de 16 bits em sensores SPI é comum em dispositivos como acelerómetros e giroscópios, onde os dados são divididos em dois bytes (MSB e LSB).  
Para efetuar esta leitura corretamente, seguem-se os seguintes passos:

1. Enviar o endereço do registo com o bit 7 ativado (`reg_addr | 0x80`), indicando uma operação de leitura.
2. Manter o sinal **CS** ativo durante toda a transação SPI.
3. Receber dois bytes consecutivos e combinar os valores num único inteiro de 16 bits: `(MSB << 8) | LSB`.

> Em sensores com suporte a leitura multibyte (como o ADXL345), é também ativado o bit 6 do endereço (`reg_addr | 0xC0`).

A implementação desta lógica encontra-se no ficheiro `.c`, utilizando uma abordagem simples e portátil para integração em qualquer microcontrolador com interface SPI.