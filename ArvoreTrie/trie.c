#include <stdlib.h>
#include <string.h>
#include "trie.h"

no trie_criarNo() {
    int i;

    no* novoNo = (*no) calloc(1, sizeof (no)); // Aloca-se um novo nó da trie

    if (novoNo != NULL) {
        for (i = 0; i < TAMANHO_ALFABETO; i++) {
            novoNo->filho[i] = NULL; // Inicializando o nó. 
        }
    }
}

void trie_adicionarPalavra(char* palavra, no* raiz) {
    int nivel = 0;
    int indice = 0;
    no* aux = raiz;

    /* Como o alfabeto não segue o padrão, deve-se calcular a posição (índice)
    de cada elemento da palavra em relação ao alfabeto */
    for (nivel = 0; nivel < strlen(palavra); nivel++) {
        if (palavra[nivel].strcmp("a")) {
            indice = 0;
        }
        if (palavra[nivel].strcmp("b")) {
            indice = 1;
        }
        if (palavra[nivel].strcmp("m")) {
            indice = 2;
        }
        if (palavra[nivel].strcmp("i")) {
            indice = 3;
        }
        if (palavra[nivel].strcmp("o")) {
            indice = 4;
        }
        /* Chegou-se no ponto onde um dos elementos da palavra não possui um nó equivalente. Deve-se criar um novo nó. */
        if (aux->filho[indice] == NULL) {
            aux->filho[indice] = trie_criarNo();
        }
        // Desce na árvore entre as posições já existentes do alfabeto, e caso contrário, cria um nó para cada letra não existente
        aux = aux->filho[indice];
    }
    aux->tipo = 'P'; // Criou-se a palavra em uma folha. 
}

int trie_calculaPosicao(char* palavra) {
    int nivel = 0;
    int posicao; // posição da letra em relação ao alfabeto. 

    for (nivel = 0; nivel < strlen(palavra); nivel++) {
        if (palavra[nivel].strcmp("a")) {
            posicao = 0;
        }
        if (palavra[nivel].strcmp("b")) {
            posicao = 1;
        }
        if (palavra[nivel].strcmp("m")) {
            posicao = 2;
        }
        if (palavra[nivel].strcmp("i")) {
            posicao = 3;
        }
        if (palavra[nivel].strcmp("o")) {
            posicao = 4;
        }
    }
}