#include <stdio.h>
#include <stdlib.h>

int main(void) {
    size_t n_inicial = 3;
    size_t n_novo = 6;

    // 1. Alocação inicial com malloc
    int *vetor = (int *) malloc(n_inicial * sizeof(int));
    if (!vetor) return EXIT_FAILURE;

    for (size_t i = 0; i < n_inicial; i++) {
        vetor[i] = (i + 1) * 10;
    }

    printf("=== Tamanho inicial (%zu elementos) ===\n", n_inicial);
    printf("Endereço original do bloco: %p\n", (void *)vetor);

    // 2. Redimensionamento com realloc
    // Boa prática: usar um ponteiro temporário para evitar perda de referência se realloc falhar
    int *temp = (int *) realloc(vetor, n_novo * sizeof(int));

    if (temp == NULL) {
        perror("Erro ao redimensionar memória com realloc");
        free(vetor); // Libera a memória original caso o realloc falhe
        return EXIT_FAILURE;
    }

    vetor = temp; // Atualiza o ponteiro principal

    // Inicializa apenas os novos elementos
    for (size_t i = n_inicial; i < n_novo; i++) {
        vetor[i] = (i + 1) * 10;
    }

    printf("\n=== Após realloc() (%zu elementos) ===\n", n_novo);
    printf("Novo endereço do bloco:     %p\n", (void *)vetor);
    for (size_t i = 0; i < n_novo; i++) {
        printf("vetor[%zu] = %d\n", i, vetor[i]);
    }

    free(vetor);
    vetor = NULL;

    return EXIT_SUCCESS;
}