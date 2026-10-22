#include <stdio.h>
#include <stdlib.h>

int main(void) {
    size_t n = 5;
    
    // Alocação para 'n' inteiros
    int *vetor = (int *) malloc(n * sizeof(int));

    // Verificação de segurança
    if (vetor == NULL) {
        perror("Erro ao alocar memória");
        return EXIT_FAILURE;
    }

    // Inicialização e exibição
    for (size_t i = 0; i < n; i++) {
        vetor[i] = (i + 1) * 10;
        printf("vetor[%zu] = %d (Endereço: %p)\n", i, vetor[i], (void *)&vetor[i]);
    }

    // Liberação da memória alocada
    free(vetor);
    vetor = NULL; // Boa prática para evitar dangling pointer

    return EXIT_SUCCESS;
}