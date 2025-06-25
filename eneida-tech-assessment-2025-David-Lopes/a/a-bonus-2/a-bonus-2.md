# Análise do Código – a-b1

## A) Compila?

Sim, o código compila sem problema com `gcc`. As `#include` estão certas e a sintaxe também, por isso à primeira vista não dá erro nenhum.

## B) Mas tem dois erros lógicos graves:

1. **Tipo da variável `i` é pequeno demais**  
   Foi usado `uint8_t`, que vai só até 255. Como o `for` vai até 1050, quando chega a 255, faz overflow e volta a 0, ou seja, nunca chega ao fim, fica num ciclo infinito.  
   O `for` continua sempre com `i <= 1050`, mas como `i` anda sempre de 0 a 255, nunca sai dali.

2. **Printf com formato errado**  
   O `%d` é para inteiros com sinal, mas como `i` é `uint8_t` (sem sinal), o certo seria utilizar `%u`. Funciona na maioria dos casos, mas pode dar valores errados.

## Como resolver

Basta trocar `uint8_t` por um tipo maior, como `uint16_t` ou até `int`, e usar `%u` no `printf`. Assim, o ciclo corre até 1050 como esperado e os valores são mostrados corretamente no terminal.