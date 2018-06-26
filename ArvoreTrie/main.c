#include <stdio.h>
#include <stdlib.h>
#include "trie.h"
#include "trie_io.h"

int main() {
    int escolha = 0;
    no* arvore;
    char nomeArquivoEnt[51];
    char palavra[TAMANHO_PALAVRA];
    int cont = 0;

    arvore = trie_criarNo();

    while (escolha != 4) {
        printf("[1] Gerar trie; \n");
        printf("[2] Pesquisar na trie; \n");
        printf("[3] Testar aplicação; \n");
        printf("[4] Sair. \n");
        scanf("%d", &escolha);
        switch (escolha) {
            case 1:
                printf("Digite o nome do arquivo que contém as palavras: ");
                scanf(" %50[^\n]", nomeArquivoEnt); // Lê o nome do arquivo de entrada de dados.

                trie_gerarArvore(arvore, nomeArquivoEnt);
                break;
            case 2:
                printf("Entre com a palavra, tia vanessa");
                scanf(" %s", palavra);
                for (int i = 0; i < strlen(palavra); i++) {
                    if ((palavra[i] = 'A') || (palavra[i] = 'B') || (palavra[i] = 'M') || (palavra[i] = 'I') || (palavra[i] = 'O')) {
                        cont++;
                    }
                }

                if (cont == strlen(palavra)) {
                    if (trie_buscaPalavra(palavra, arvore) == 1) {
                        printf("Achamos sua palavra!! aee");
                    } else {
                        printf("Palavra não encontrada");
                    }
                } else {
                    printf("Não achamos sua palavra. :/");
                }
                break;
            case 3:
                break;
            case 4:
                break;
        }
    }

    return 0;
}

