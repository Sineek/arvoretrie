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

/* Percorre a TRIE, comparando os elementos da palavra e os prefixos já existentes na árvore. 
Se o prefixo em questão não estiver no ramo avaliado, cria-se um nó para conter o prefixo não existente e assim sucessivamente, 
até que a palavra esteja criada. */
void trie_adicionarPalavra(char* palavra, no* raiz) {
    int nivel = 0;
    int indice = 0;
    no* aux = raiz;

    /* Como o alfabeto não segue o padrãodo alfabeto português de 26 letras, deve-se calcular a posição (índice)
    de cada elemento da palavra em relação ao alfabeto */
    for (nivel = 0; nivel < strlen(palavra); nivel++) {
        if (palavra[nivel].strcmp("a")) { // Letra 'a' está na posição 0 no alfabeto
            indice = 0;
        }
        if (palavra[nivel].strcmp("b")) { // Letra 'b' está na posição 1 no alfabeto
            indice = 1;
        }
        if (palavra[nivel].strcmp("m")) { // Letra 'm' está na posição 2 no alfabeto
            indice = 2;
        }
        if (palavra[nivel].strcmp("i")) { // Letra 'i' está na posição 3 no alfabeto
            indice = 3;
        }
        if (palavra[nivel].strcmp("o")) { // Letra 'o' está na posição 4 no alfabeto
            indice = 4;
        }
        /* Chegou-se no ponto onde um dos elementos da palavra não possui um nó/prefixo equivalente presente na árvore.
        Deve-se criar um novo nó para conter o elemento/prefixo não existente. */
        if (aux->filho[indice] == NULL) {
            aux->filho[indice] = trie_criarNo();
        }
        // Atualização de ponteiros para caminhar na TRIE: Desce na árvore entre os prefixos já existentes no ramo
        aux = aux->filho[indice];
    }
    aux->tipo = 'P'; // Criou-se a palavra em uma folha. 
}

