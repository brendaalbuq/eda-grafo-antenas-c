// Arquivo: grafo.c
#include <stdio.h>
#include <stdlib.h>
#include "../include/grafo.h"

/**
 * @brief Cria um grafo vazio.
 * @return Apontador para o grafo criado.
 */
Grafo* criarGrafo() {
    Grafo *g = (Grafo*)malloc(sizeof(Grafo));
    if (!g) {
        fprintf(stderr, "Erro ao alocar memoria para o grafo!\n");
        exit(1);
    }
    g->vertices = NULL;
    return g;
}

/**
 * @brief Adiciona um vértice ao grafo.
 * @param g Apontador para o grafo.
 * @param antena Apontador para a antena que será representada pelo vértice.
 * @return Apontador para o vértice criado.
 */
Vertice* adicionarVertice(Grafo *g, Antena *antena) {
    Vertice *novo = (Vertice*)malloc(sizeof(Vertice));
    if (!novo) {
        fprintf(stderr, "Erro ao alocar memoria para o vertice!\n");
        exit(1);
    }
    novo->antena = antena;
    novo->adj = NULL;
    novo->prox = g->vertices;
    g->vertices = novo;
    return novo;
}

/**
 * @brief Adiciona uma aresta entre dois vértices.
 * @param origem Vértice de origem.
 * @param destino Vértice de destino.
 * @return Apontador para a aresta criada.
 */
Aresta* adicionarAresta(Vertice *origem, Vertice *destino) {
    Aresta *nova = (Aresta*)malloc(sizeof(Aresta));
    if (!nova) {
        fprintf(stderr, "Erro ao alocar memoria para a aresta!\n");
        exit(1);
    }
    nova->destino = destino;
    nova->prox = origem->adj;
    origem->adj = nova;
    return nova;
}

/**
 * @brief Lista todos os vértices do grafo.
 * @param g Apontador para o grafo.
 */
void listarVertices(Grafo *g) {
    Vertice *v = g->vertices;
    printf("\n=== Lista de Vertices do Grafo ===\n");
    while (v) {
        printf("Vertice: %c (%d, %d)\n", v->antena->freq, v->antena->x, v->antena->y);
        v = v->prox;
    }
}

/**
 * @brief Libera toda a memória ocupada pelo grafo.
 * @param g Apontador para o grafo.
 */
void liberarGrafo(Grafo *g) {
    Vertice *v = g->vertices;
    while (v) {
        Aresta *a = v->adj;
        while (a) {
            Aresta *tempA = a;
            a = a->prox;
            free(tempA);
        }
        Vertice *tempV = v;
        v = v->prox;
        free(tempV);
    }
    free(g);
}

/**
 * @brief Busca um vértice no grafo pelas coordenadas.
 * @param g Apontador para o grafo.
 * @param x Coordenada X do vértice a ser buscado.
 * @param y Coordenada Y do vértice a ser buscado.
 * @return Apontador para o vértice encontrado ou NULL se não encontrado.
 */
Vertice* buscarVertice(Grafo *g, int x, int y) {
    Vertice *v = g->vertices;
    while (v) {
        if (v->antena->x == x && v->antena->y == y)
            return v;
        v = v->prox;
    }
    return NULL;
}

/**
 * @brief Conecta todos os vértices do grafo com base na frequência e proximidade.
 * @param g Apontador para o grafo.
 */
void conectarVertices(Grafo *g) {
    Vertice *v1 = g->vertices;
    while (v1) {
        Vertice *v2 = g->vertices;
        while (v2) {
            if (v1 != v2 && v1->antena->freq == v2->antena->freq) {
                int dx = abs(v1->antena->x - v2->antena->x);
                int dy = abs(v1->antena->y - v2->antena->y);
                // Conecta apenas se os vértices estão adjacentes
                if ((dx == 1 && dy == 0) || (dx == 0 && dy == 1)) {
                    adicionarAresta(v1, v2);
                    adicionarAresta(v2, v1);
                }
            }
            v2 = v2->prox;
        }
        v1 = v1->prox;
    }
}
