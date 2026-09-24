# Grafo de antenas em C

Projeto da UC de Estruturas de Dados Avançadas da Licenciatura em Engenharia de Sistemas Informáticos (IPCA), no ano letivo 2024/25.

O programa lê um mapa de antenas a partir de um ficheiro de texto, em que cada letra representa uma antena com uma frequência e a sua posição na grelha. A partir desse mapa, constrói estruturas de dados dinâmicas e aplica algoritmos de procura sobre elas.

## Funcionalidades

- Carregamento das antenas do ficheiro para uma **lista ligada**
- Construção de um **grafo com listas de adjacência**, ligando antenas adjacentes da mesma frequência
- Procura em profundidade (**DFS**) e em largura (**BFS**) a partir de uma antena
- Listagem de **caminhos** entre duas antenas
- Listagem de **interseções** entre antenas de frequências diferentes
- Deteção de **efeitos nefastos** (posições afetadas pelo alinhamento de antenas da mesma frequência)
- Menu interativo na consola

## Estrutura

```
include/   cabeçalhos com as estruturas e a documentação das funções (Doxygen)
src/       antenas.c (lista ligada), grafo.c (grafo), buscas.c (DFS, BFS, caminhos), main.c (menu)
testes/    antenas.txt, mapa de exemplo
```

## Compilar e executar

```bash
make
make run
```

Exemplo de mapa (`testes/antenas.txt`):

```
...........A..
.......B......
.....C........
....A.........
```

## Tecnologias

C · gcc · Make · Doxygen
