#include <stdio.h>
#include <stdlib.h>

int main(void) {
    size_t n = 5;

    // calloc(numero_elementos, tamanho_cada_elemento)
    // Garante que todos os bytes sejam inicializados com 0
    int *vetor_calloc = (int *) calloc(n, sizeof(int));

    if (vetor_calloc == NULL) {
        perror("Erro ao alocar memória com calloc");
        return EXIT_FAILURE;
    }

    printf("=== Valores alocados via calloc() (devem ser todos 0) ===\n");
    for (size_t i = 0; i < n; i++) {
        printf("vetor_calloc[%zu] = %d\n", i, vetor_calloc[i]);
    }

    free(vetor_calloc);
    vetor_calloc = NULL;

    return EXIT_SUCCESS;
}