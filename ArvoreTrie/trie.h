#ifndef TRIE_H
#define	TRIE_H

#define TAMANHO_ALFABETO (5)
#define TAMANHO_PALAVRA (30)

struct no { 
	char tipoNo; // 'I': nó interno | 'P': nó palavra
	struct no* filho[TAMANHO_ALFABETO];	
};

typedef struct no no; 

#endif	/* TRIE_H */

