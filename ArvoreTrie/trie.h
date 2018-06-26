#include <stdlib.h>
#include <string.h>

#ifndef TRIE_H
#define	TRIE_H

#define TAMANHO_ALFABETO (6) /* Alfabeto formado pelas letras maiúsculas ABMIO mais um elemento para significar o fim do alfabeto. */
#define TAMANHO_PALAVRA (30)

struct no {
    char tipo; // Pode ser 'I': nó interno ou 'P': nó de informação/palavra
    struct no* filho[TAMANHO_ALFABETO];
};

typedef struct no no;

no trie_criarNo();
void trie_adicionarPalavra(char* palavra, no* raiz);
int trie_buscaPalavra(char* palavra, no* raiz);















#endif	/* TRIE_H */

