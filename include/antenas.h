#ifndef ANTENAS_H
#define ANTENAS_H

/**
 * @struct Antena
 * @brief Estrutura para representar uma antena em uma lista ligada.
 */
typedef struct antena {
    char freq; /**< Frequência da antena. */
    int x, y; /**< Coordenadas da antena no mapa. */
    struct antena *prox; /**< Apontador para a próxima antena na lista. */
} Antena;

/**
 * @brief Cria uma nova antena.
 * @param freq Frequência da antena.
 * @param x Coordenada X da antena.
 * @param y Coordenada Y da antena.
 * @return Apontador para a nova antena criada.
 */
Antena* criarAntena(char freq, int x, int y);

/**
 * @brief Insere uma nova antena na lista ligada.
 * @param head Cabeça da lista ligada de antenas.
 * @param freq Frequência da nova antena.
 * @param x Coordenada X da antena.
 * @param y Coordenada Y da antena.
 * @return Apontador para a cabeça atualizada da lista ligada.
 */
Antena* inserirAntena(Antena *head, char freq, int x, int y);

/**
 * @brief Lista todas as antenas presentes na lista ligada.
 * @param head Cabeça da lista ligada de antenas.
 */
void listarAntenas(Antena *head);

/**
 * @brief Carrega antenas de um arquivo para uma lista ligada.
 * @param filename Nome do arquivo contendo as antenas.
 * @return Cabeça da lista ligada carregada.
 */
Antena* carregarAntenas(const char *filename);

/**
 * @brief Libera a memória ocupada pela lista de antenas.
 * @param head Cabeça da lista ligada de antenas.
 */
void liberarAntenas(Antena *head);

/**
 * @brief Lista os efeitos nefastos das antenas.
 * @param head Cabeça da lista ligada de antenas.
 */
void listarEfeitosNefastos(Antena *head);

#endif
