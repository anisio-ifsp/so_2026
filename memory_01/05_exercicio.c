/*
 * ============================================================================
 *                          ENUNCIADO DO EXERCÍCIO
 * ============================================================================
 * 
 * OBJETIVO:
 * Implementar o gerenciamento dinâmico de memória em C utilizando struct, 
 * malloc(), realloc() e free() para criar um histórico expansível de leituras 
 * de sensores de temperatura.
 * 
 * CONTEXTO:
 * Você foi encarregado de criar o módulo de armazenamento de dados de um 
 * sistema de monitoramento de temperatura. Como não se sabe previamente quantas 
 * leituras serão registradas, os dados devem ser armazenados em um vetor dinâmico 
 * no Heap que cresce conforme a necessidade.
 * 
 * ESTRUTURA DO PROGRAMA:
 * 1. Struct `LeituraSensor`: Representa cada leitura individual (contendo ID e temperatura).
 * 2. Struct `HistoricoSensores`: Gerencia o ponteiro para o vetor no Heap, a quantidade de 
 *    registros armazenados e a capacidade máxima atual.
 * 
 * TAREFAS A SEREM IMPLEMENTADAS (TODOS):
 * 
 * - TODO 1: Alocação Inicial
 *   Aloque dinamicamente no Heap o vetor de leituras dentro da struct `historico` 
 *   utilizando a função `malloc()` com base na capacidade inicial (`historico.capacidade`).
 * 
 * - TODO 2: Realocação / Expansão Dinâmica
 *   Quando o número de leituras atingir a capacidade máxima, redimensione o vetor 
 *   `historico.leituras` utilizando `realloc()`, expandindo a memória para acomodar 
 *   a `nova_capacidade`.
 * 
 * - TODO 3: Liberação de Memória
 *   Libere a memória alocada no Heap antes do encerramento do programa 
 *   utilizando a função `free()`.
 * 
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

// Struct que representa uma leitura individual
typedef struct {
    int id;
    float temperatura;
} LeituraSensor;

// Struct que gerencia o vetor dinâmico
typedef struct {
    LeituraSensor *leituras; // Ponteiro para o vetor no Heap
    int quantidade;          // Quantidade de leituras salvas
    int capacidade;          // Capacidade máxima atual do vetor
} HistoricoSensores;

int main(void) {
    HistoricoSensores historico;
    historico.quantidade = 0;
    historico.capacidade = 2; // Capacidade inicial para 2 leituras

    // =========================================================================
    // TODO 1: Aloque dinamicamente o vetor 'leituras' dentro da struct 'historico'
    // Dica: Use malloc() para a capacidade inicial (historico.capacidade)
    // =========================================================================
    historico.leituras = /* SEU CÓDIGO AQUI */;

    // Verificação de segurança
    if (historico.leituras == NULL) {
        printf("Erro ao alocar memória inicial!\n");
        return 1;
    }

    printf("[SISTEMA] Memória inicial alocada no Heap para %d leituras. Endereço: %p\n", 
           historico.capacidade, (void *)historico.leituras);

    int opcao = 1;
    float temp_input;

    while (opcao != 0) {
        printf("\n1. Inserir nova leitura de temperatura\n");
        printf("2. Exibir histórico de leituras\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            // Verificar se precisamos de mais espaço
            if (historico.quantidade == historico.capacidade) {
                int nova_capacidade = historico.capacidade + 2; // Aumenta de 2 em 2

                // =========================================================================
                // TODO 2: Redimencione o vetor 'leituras' usando realloc()
                // Dica: Atualize historico.leituras para apontar para a nova memória
                // =========================================================================
                historico.leituras = /* SEU CÓDIGO AQUI */;

                if (historico.leituras == NULL) {
                    printf("Erro ao expandir memória com realloc!\n");
                    return 1;
                }

                historico.capacidade = nova_capacidade;
                printf(" -> [MEMÓRIA EXPANDIDA] Nova capacidade: %d | Novo endereço Heap: %p\n", 
                       historico.capacidade, (void *)historico.leituras);
            }

            // Inserção do dado no vetor
            printf("Digite a temperatura em °C: ");
            scanf("%f", &temp_input);

            int idx = historico.quantidade;
            historico.leituras[idx].id = idx + 1;
            historico.leituras[idx].temperatura = temp_input;
            historico.quantidade++;

            printf("Leitura #%d salva com sucesso!\n", historico.quantidade);

        } else if (opcao == 2) {
            printf("\n=== HISTÓRICO DE LEITURAS (%d/%d usados) ===\n", 
                   historico.quantidade, historico.capacidade);
            
            for (int i = 0; i < historico.quantidade; i++) {
                printf("ID: %d | Temp: %.1f°C | Endereço de Memória: %p\n", 
                       historico.leituras[i].id, 
                       historico.leituras[i].temperatura, 
                       (void *)&historico.leituras[i]);
            }
        }
    }

    // =========================================================================
    // TODO 3: Liberte a memória alocada no Heap antes de encerrar o programa
    // Dica: Use a função free() no ponteiro correto
    // =========================================================================
    /* SEU CÓDIGO AQUI */;

    printf("\n[SISTEMA] Memória do Heap liberada com sucesso. Encerrando programa.\n");
    return 0;
}