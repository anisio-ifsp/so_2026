#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
    printf("PID do processo: %d\n", getpid());
    
    // Aloca 10 MB no Heap
    size_t tamanho = 10 * 1024 * 1024;
    char *bloco = (char *) malloc(tamanho);

    if (!bloco) {
        perror("Falha no malloc");
        return 1;
    }

    printf("Alocado 10 MB no endereço %p.\n", (void *)bloco);
    printf("Execute em outro terminal: cat /proc/%d/maps | grep -E 'heap|stack'\n", getpid());
    printf("Pressione ENTER para liberar a memória e encerrar...\n");
    
    getchar();

    free(bloco);
    return 0;
}