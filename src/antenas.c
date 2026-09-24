// Arquivo: antenas.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/antenas.h"

/**
 * @brief Cria uma nova antena.
 * @param freq Frequência da antena.
 * @param x Coordenada X da antena.
 * @param y Coordenada Y da antena.
 * @return Apontador para a nova antena criada.
 */
Antena* criarAntena(char freq, int x, int y) {
    Antena *nova = (Antena*)malloc(sizeof(Antena));
    if (!nova) {
        fprintf(stderr, "Erro ao alocar memoria para nova antena!\n");
        exit(1);
    }
    nova->freq = freq;
    nova->x = x;
    nova->y = y;
    nova->prox = NULL;
    return nova;
}

/**
 * @brief Insere uma nova antena na lista ligada.
 * @param head Cabeça da lista ligada de antenas.
 * @param freq Frequência da nova antena.
 * @param x Coordenada X da antena.
 * @param y Coordenada Y da antena.
 * @return Apontador para a cabeça atualizada da lista ligada.
 */
Antena* inserirAntena(Antena *head, char freq, int x, int y) {
    Antena *nova = criarAntena(freq, x, y);
    nova->prox = head;
    return nova;
}

/**
 * @brief Lista todas as antenas presentes na lista ligada.
 * @param head Cabeça da lista ligada de antenas.
 */
void listarAntenas(Antena *head) {
    if (!head) {
        printf("Lista de antenas vazia.\n");
        return;
    }
    Antena *atual = head;
    printf("Frequencia\tCoordenadas\n");
    printf("----------------------------\n");
    while (atual) {
        printf("%c\t(%d, %d)\n", atual->freq, atual->x, atual->y);
        atual = atual->prox;
    }
}

/**
 * @brief Libera a memória ocupada pela lista de antenas.
 * @param head Cabeça da lista ligada de antenas.
 */
void liberarAntenas(Antena *head) {
    while (head) {
        Antena *temp = head;
        head = head->prox;
        free(temp);
    }
}

/**
 * @brief Carrega antenas de um arquivo para uma lista ligada.
 * @param filename Nome do arquivo contendo as antenas.
 * @return Cabeça da lista ligada carregada.
 */
Antena* carregarAntenas(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Erro ao abrir arquivo");
        exit(1);
    }
    Antena *head = NULL;
    char linha[256];
    int y = 0;
    while (fgets(linha, sizeof(linha), file)) {
        for (int x = 0; linha[x] != '\0'; x++) {
            if ((linha[x] == 'A' || linha[x] == 'B' || linha[x] == 'C') && linha[x] != '\n') {
                head = inserirAntena(head, linha[x], x, y);
            }
        }
        y++;
    }
    fclose(file);
    return head;
}

/**
 * @brief Lista os efeitos nefastos das antenas.
 * @param head Cabeça da lista ligada de antenas.
 */
void listarEfeitosNefastos(Antena *head) {
    if (!head) {
        printf("\nNenhuma antena carregada.\n");
        return;
    }
    printf("\n=== Efeitos Nefastos ===\n");
    int encontrou = 0;
    Antena *a = head;
    while (a) {
        Antena *b = head;
        while (b) {
            if (a != b && a->freq == b->freq) {
                int dx = a->x - b->x;
                int dy = a->y - b->y;
                int dist = dx * dx + dy * dy;
                if (dist == 4) {
                    int nefastoX = a->x + 2 * dx;
                    int nefastoY = a->y + 2 * dy;
                    printf("Efeito nefasto causado por %c (%d, %d) em (%d, %d)\n",
                           a->freq, a->x, a->y, nefastoX, nefastoY);
                    encontrou = 1;
                }
            }
            b = b->prox;
        }
        a = a->prox;
    }
    if (!encontrou) {
        printf("Nenhum efeito nefasto encontrado.\n");
    }
}
