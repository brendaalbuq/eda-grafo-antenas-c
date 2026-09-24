// Arquivo: buscas.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/buscas.h"
#include "../include/grafo.h"

/**
 * @brief Realiza busca em profundidade (DFS) a partir de um vértice.
 * @param g Apontador para o grafo.
 * @param x Coordenada X do vértice de partida.
 * @param y Coordenada Y do vértice de partida.
 */
void DFS(Grafo *g, int x, int y) {
    Vertice *inicio = buscarVertice(g, x, y);
    if (!inicio) {
        printf("Antena (%d, %d) nao encontrada para DFS.\n", x, y);
        return;
    }

    int visitado[10000] = {0};
    Vertice *pilha[1000];
    int topo = 0;
    pilha[topo++] = inicio;
    visitado[(inicio->antena->x * 100) + inicio->antena->y] = 1;

    printf("\n=== Resultado da Busca em Profundidade (DFS) ===\n");
    while (topo > 0) {
        Vertice *atual = pilha[--topo];
        printf("Antena %c (%d, %d)\n", atual->antena->freq, atual->antena->x, atual->antena->y);
        Aresta *a = atual->adj;
        while (a) {
            int key = (a->destino->antena->x * 100) + a->destino->antena->y;
            if (!visitado[key]) {
                pilha[topo++] = a->destino;
                visitado[key] = 1;
            }
            a = a->prox;
        }
    }
}

/**
 * @brief Realiza busca em largura (BFS) a partir de um vértice.
 * @param g Apontador para o grafo.
 * @param x Coordenada X do vértice de partida.
 * @param y Coordenada Y do vértice de partida.
 */
void BFS(Grafo *g, int x, int y) {
    Vertice *inicio = buscarVertice(g, x, y);
    if (!inicio) {
        printf("Antena (%d, %d) nao encontrada para BFS.\n", x, y);
        return;
    }

    int visitado[10000] = {0};
    Vertice *fila[1000];
    int inicioFila = 0, fimFila = 0;
    fila[fimFila++] = inicio;
    visitado[(inicio->antena->x * 100) + inicio->antena->y] = 1;

    printf("\n=== Resultado da Busca em Largura (BFS) ===\n");
    while (inicioFila < fimFila) {
        Vertice *atual = fila[inicioFila++];
        printf("Antena %c (%d, %d)\n", atual->antena->freq, atual->antena->x, atual->antena->y);
        Aresta *a = atual->adj;
        while (a) {
            int key = (a->destino->antena->x * 100) + a->destino->antena->y;
            if (!visitado[key]) {
                fila[fimFila++] = a->destino;
                visitado[key] = 1;
            }
            a = a->prox;
        }
    }
}

/**
 * @brief Lista todos os caminhos possíveis entre dois vértices usando DFS.
 * @param g Apontador para o grafo.
 * @param x1 Coordenada X do vértice de origem.
 * @param y1 Coordenada Y do vértice de origem.
 * @param x2 Coordenada X do vértice de destino.
 * @param y2 Coordenada Y do vértice de destino.
 */
void listarCaminhos(Grafo *g, int x1, int y1, int x2, int y2) {
    Vertice *origem = buscarVertice(g, x1, y1);
    Vertice *destino = buscarVertice(g, x2, y2);
    if (!origem || !destino) {
        printf("Um dos vertices nao foi encontrado.\n");
        return;
    }

    printf("\n=== Caminhos entre (%d, %d) e (%d, %d) ===\n", x1, y1, x2, y2);

    int visitado[10000] = {0};
    Vertice *pilha[1000];
    int topo = 0;
    pilha[topo++] = origem;
    visitado[(origem->antena->x * 100) + origem->antena->y] = 1;

    while (topo > 0) {
        Vertice *atual = pilha[--topo];
        if (atual == destino) {
            printf("%c (%d, %d) - FIM\n", atual->antena->freq, atual->antena->x, atual->antena->y);
            continue;
        }
        printf("%c (%d, %d) -> ", atual->antena->freq, atual->antena->x, atual->antena->y);
        Aresta *a = atual->adj;
        while (a) {
            int key = (a->destino->antena->x * 100) + a->destino->antena->y;
            if (!visitado[key]) {
                pilha[topo++] = a->destino;
                visitado[key] = 1;
            }
            a = a->prox;
        }
    }
}

/**
 * @brief Lista todas as interseções entre duas frequências diferentes.
 * @param g Apontador para o grafo.
 * @param freqA Frequência do primeiro grupo de antenas.
 * @param freqB Frequência do segundo grupo de antenas.
 */
void listarIntersecoes(Grafo *g, char freqA, char freqB) {
    Vertice *v1 = g->vertices;
    printf("\n=== Intersecoes entre Frequencias %c e %c ===\n", freqA, freqB);
    while (v1) {
        if (v1->antena->freq == freqA || v1->antena->freq == freqB) {
            Vertice *v2 = g->vertices;
            while (v2) {
                if (v2 != v1 && (v2->antena->freq == freqA || v2->antena->freq == freqB)) {
                    if (v1->antena->freq != v2->antena->freq) {
                        printf("%c (%d, %d) <-> %c (%d, %d)\n",
                               v1->antena->freq, v1->antena->x, v1->antena->y,
                               v2->antena->freq, v2->antena->x, v2->antena->y);
                    }
                }
                v2 = v2->prox;
            }
        }
        v1 = v1->prox;
    }
}
