// Arquivo: main.c
#include <stdio.h>
#include <stdlib.h>
#include "../include/antenas.h"
#include "../include/grafo.h"
#include "../include/buscas.h"

/**
 * @brief Exibe o menu principal do programa.
 */
void exibirMenu() {
    printf("\n====================================\n");
    printf("          MENU PRINCIPAL\n");
    printf("====================================\n");
    printf("1. Carregar Antenas\n");
    printf("2. Criar Grafo\n");
    printf("3. Listar Antenas\n");
    printf("4. Listar Vertices do Grafo\n");
    printf("5. Teste de DFS\n");
    printf("6. Teste de BFS\n");
    printf("7. Teste de Caminhos\n");
    printf("8. Teste de Intersecoes\n");
    printf("9. Mostrar Efeitos Nefastos\n");
    printf("10. Sair\n");
    printf("====================================\n");
    printf("Escolha uma opcao: ");
}

/**
 * @brief Função principal do programa.
 * @return Codigo de saida do programa.
 */
int main() {
    Antena *antenas = NULL;
    Grafo *grafo = NULL;
    int opcao;

    do {
        exibirMenu();
        if (scanf("%d", &opcao) != 1) {
            printf("\nErro: Entrada invalida. Por favor, insira um numero.\n");
            while (getchar() != '\n'); // Limpa o buffer do teclado
            continue;
        }

        switch (opcao) {
            case 1:
                antenas = carregarAntenas("testes/antenas.txt");
                if (antenas) {
                    printf("\nAntenas carregadas com sucesso!\n");
                } else {
                    printf("\nErro ao carregar antenas. Verifique o arquivo de entrada.\n");
                }
                break;
            case 2:
                grafo = criarGrafo();
                Antena *atual = antenas;
                while (atual) {
                    adicionarVertice(grafo, atual);
                    atual = atual->prox;
                }
                printf("\nGrafo criado com sucesso!\n");
                break;
            case 3:
                printf("\n=== Lista de Antenas ===\n");
                listarAntenas(antenas);
                break;
            case 4:
                printf("\n=== Lista de Vertices do Grafo ===\n");
                listarVertices(grafo);
                break;
            case 5:
                printf("\nTeste de DFS\n");
                DFS(grafo, 4, 4);
                break;
            case 6:
                printf("\nTeste de BFS\n");
                BFS(grafo, 4, 4);
                break;
            case 7:
                printf("\nTeste de Caminhos\n");
                listarCaminhos(grafo, 4, 4, 8, 8);
                break;
            case 8:
                printf("\nTeste de Intersecoes\n");
                listarIntersecoes(grafo, 'A', 'B');
                break;
            case 9:
                printf("\n=== Efeitos Nefastos ===\n");
                listarEfeitosNefastos(antenas);
                break;
            case 10:
                printf("\nSaindo...\n");
                liberarAntenas(antenas);
                liberarGrafo(grafo);
                printf("\nMemoria liberada com sucesso.\n");
                break;
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }
    } while (opcao != 10);

    return 0;
}
