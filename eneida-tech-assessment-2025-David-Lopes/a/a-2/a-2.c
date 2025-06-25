#include <stdio.h>
#include <stdint.h>

// Variaveis
#define BUFFER_SIZE 128
uint8_t buffer[BUFFER_SIZE];
int tail = 0;
int head = 0;

// Inicia
void init(){
    head = 0;
    tail = 0;
}

// Verifica se o buffer está vazio
int is_empty(){
    return head == tail;
}

// Verifica se o buffer está cheio
int is_full(){
    return (tail + 1) % BUFFER_SIZE == head;
}

// Insere valor
int push(uint8_t value){
    if (is_full()) return 0; // Não faz nada se estiver cheio

    buffer[tail] = value;
    tail = (tail + 1) % BUFFER_SIZE;
    return 1;
}

// Remove valor
int pop(uint8_t *value) {
    if (is_empty()) return 0; // Não faz nada se estiver vazio

    *value = buffer[head];
    head = (head + 1) % BUFFER_SIZE;
    return 1;
}

// Main
int main() {
    // Inicializa
    init();

    // Insere
    push(10);
    push(20);
    push(30);

    // Retira e imprime
    uint8_t val;
    while (pop(&val)) {
        printf("Valor lido: %u\n", val);
    }

    return 0;
}