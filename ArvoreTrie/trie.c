#include <stdlib.h>
#include <string.h>
#include "trie.h"

/* Cria um nó vazio da árvore TRIE */
no trie_criarNo() {
    int i;

    no* novoNo = (*no) calloc(1, sizeof (no)); // Aloca-se um novo nó da trie.

    if (novoNo != NULL) {
    	novoNo->tipo = 'I'; // O novo nó criado é do tipo 'Interno'
        for (i = 0; i < TAMANHO_ALFABETO; i++) {
            novoNo->filho[i] = NULL; // Inicializando o nó: cada campo tem valor nulo. 
        }
    }

    return novoNo; 
}

/* Percorre a TRIE, comparando os elementos da palavra e os prefixos já existentes na árvore. 
Se o prefixo em questão não estiver no ramo avaliado, cria-se um nó para conter o prefixo não existente e assim sucessivamente, 
até que a palavra esteja criada. */
void trie_adicionarPalavra(char* palavra, no* raiz) {
    int nivel = 0;
    int indice = 0;
    no* aux = raiz;

    /* Como o alfabeto não segue o padrão do alfabeto português de 26 letras, deve-se calcular a posição (índice)
    de cada elemento da palavra em relação ao alfabeto */
    for (nivel = 0; nivel < strlen(palavra); nivel++) {
        if (palavra[nivel].strcmp("A")) { // Letra 'a' está na posição 0 no alfabeto
            indice = 0;
        }
        if (palavra[nivel].strcmp("B")) { // Letra 'b' está na posição 1 no alfabeto
            indice = 1;
        }
        if (palavra[nivel].strcmp("M")) { // Letra 'm' está na posição 2 no alfabeto
            indice = 2;
        }
        if (palavra[nivel].strcmp("I")) { // Letra 'i' está na posição 3 no alfabeto
            indice = 3;
        }
        if (palavra[nivel].strcmp("O")) { // Letra 'o' está na posição 4 no alfabeto
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
    aux->tipo = 'P'; // Criou-se a palavra. 
}

/* Função responsável por verificar se uma palavra se encontra ou não na árvore. Retorna o número 1 em caso afirmativo, e 0
caso contrário. A função consecutivamente captura cada elemento da palavra, calcula a sua posição/índice equivalente no próximo
nó e passa a avaliar esse nó, verificando assim se todos os elementos formadores da palavra estão presentes sequencialmente em 
um dos caminhos da árvore (busca com sucesso). */
int trie_buscaPalavra(char* palavra, no* raiz) {
	int i = 0;
	int indice = 0; // Posição que a palavra ocupa em relação ao alfabeto 
	no* aux = raiz; // nó auxiliar para caminhar na árvore

	/* Como o alfabeto não segue o padrão do alfabeto português de 26 letras, deve-se calcular a posição (índice)
	de cada elemento da palavra em relação ao alfabeto */
	for (i = 0; i < strlen(palavra); i++) {
	    if (palavra[i].strcmp("A")) { // Letra 'A' está na posição 0 no alfabeto/vetor
	        indice = 0;
	    }
	    if (palavra[i].strcmp("B")) { // Letra 'B' está na posição 1 no alfabeto/vetor
	        indice = 1;
	    }
	    if (palavra[i].strcmp("M")) { // Letra 'M' está na posição 2 no alfabeto/vetor
	        indice = 2;
	    }
	    if (palavra[i].strcmp("I")) { // Letra 'I' está na posição 3 no alfabeto/vetor
	        indice = 3;
	    }
	    if (palavra[i].strcmp("O")) { // Letra 'O' está na posição 4 no alfabeto/vetor
	        indice = 4;
	    }

	    /* Desce na árvore comparando os prefixos existentes no caminho com cada elemento da palavra, de modo semelhante à
	    trie_adicionarPalavra.   */
	    if(aux->filho[indice] != NULL) {
	    	aux = aux->filho[indice]; 
	    } else {
	    	return 0; 
	    }	    
	}

	if(palavra[i] == '\0' && aux->tipo == 'P') {
		return 1; // A palavra se encontra na árvore. 
	} else {
		return 0; // A palavra não se encontra na árvore. 
	}
}

