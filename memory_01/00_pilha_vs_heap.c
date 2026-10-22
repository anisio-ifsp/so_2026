#include <stdio.h>
#include <stdlib.h>

int global_var = 42; // Fica no segmento .data

void examinar_memoria(int param) {
    int local_stack_var = 10;
    int *heap_var = (int *) malloc(sizeof(int));
    *heap_var = 99;

    printf("=== Layout do Espaço de Endereçamento ===\n");
    printf("[.text / Código] Endereço da função:     %p\n", (void *)examinar_memoria);
    printf("[.data / Global] Endereço de global_var:  %p\n", (void *)&global_var);
    printf("[Stack / Pilha]  Endereço do parâmetro:   %p\n", (void *)&param);
    printf("[Stack / Pilha]  Endereço da var local:   %p\n", (void *)&local_stack_var);
    printf("[Heap / Dinâmico] Endereço retornado por malloc: %p\n", (void *)heap_var);

    free(heap_var);
}

int main(void) {
    examinar_memoria(5);
    return 0;
}