#ifndef GRAFO_H
#define GRAFO_H

#include "antenas.h"

/**
 * @struct Vertice
 * @brief Estrutura para representar vértices no grafo.
 */
typedef struct vertice {
    Antena *antena; /**< Apontador para a antena representada pelo vértice. */
    struct aresta *adj; /**< Lista de adjacências para outros vértices. */
    struct vertice *prox; /**< Próximo vértice na lista do grafo. */
} Vertice;

/**
 * @struct Aresta
 * @brief Estrutura para representar arestas no grafo.
 */
typedef struct aresta {
    Vertice *destino; /**< Vértice de destino desta aresta. */
    struct aresta *prox; /**< Próxima aresta na lista de adjacências. */
} Aresta;

/**
 * @struct Grafo
 * @brief Estrutura para representar o grafo completo.
 */
typedef struct {
    Vertice *vertices; /**< Lista de todos os vértices do grafo. */
} Grafo;

/**
 * @brief Cria um grafo vazio.
 * @return Apontador para o grafo criado.
 */
Grafo* criarGrafo();

/**
 * @brief Adiciona um vértice ao grafo.
 * @param g Apontador para o grafo.
 * @param antena Apontador para a antena que será representada pelo vértice.
 * @return Apontador para o vértice criado.
 */
Vertice* adicionarVertice(Grafo *g, Antena *antena);

/**
 * @brief Adiciona uma aresta entre dois vértices.
 * @param origem Vértice de origem.
 * @param destino Vértice de destino.
 * @return Apontador para a aresta criada.
 */
Aresta* adicionarAresta(Vertice *origem, Vertice *destino);

/**
 * @brief Libera toda a memória ocupada pelo grafo.
 * @param g Apontador para o grafo.
 */
void liberarGrafo(Grafo *g);

/**
 * @brief Lista todos os vértices do grafo.
 * @param g Apontador para o grafo.
 */
void listarVertices(Grafo *g);

/**
 * @brief Busca um vértice no grafo pelas coordenadas.
 * @param g Apontador para o grafo.
 * @param x Coordenada X do vértice a ser buscado.
 * @param y Coordenada Y do vértice a ser buscado.
 * @return Apontador para o vértice encontrado ou NULL se não encontrado.
 */
Vertice* buscarVertice(Grafo *g, int x, int y);

#endif
