#ifndef BUSCAS_H
#define BUSCAS_H

#include "grafo.h"

/**
 * @brief Realiza busca em profundidade (DFS) a partir de um vértice.
 * @param g Apontador para o grafo.
 * @param x Coordenada X do vértice de partida.
 * @param y Coordenada Y do vértice de partida.
 */
void DFS(Grafo *g, int x, int y);

/**
 * @brief Realiza busca em largura (BFS) a partir de um vértice.
 * @param g Apontador para o grafo.
 * @param x Coordenada X do vértice de partida.
 * @param y Coordenada Y do vértice de partida.
 */
void BFS(Grafo *g, int x, int y);

/**
 * @brief Lista todos os caminhos possíveis entre dois vértices.
 * @param g Apontador para o grafo.
 * @param x1 Coordenada X do vértice de origem.
 * @param y1 Coordenada Y do vértice de origem.
 * @param x2 Coordenada X do vértice de destino.
 * @param y2 Coordenada Y do vértice de destino.
 */
void listarCaminhos(Grafo *g, int x1, int y1, int x2, int y2);

/**
 * @brief Lista todas as interseções entre duas frequências diferentes.
 * @param g Apontador para o grafo.
 * @param freqA Frequência do primeiro grupo de antenas.
 * @param freqB Frequência do segundo grupo de antenas.
 */
void listarIntersecoes(Grafo *g, char freqA, char freqB);

#endif
