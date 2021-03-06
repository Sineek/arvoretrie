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

                printf("Entre com a palavra, tia vanessa\n");

                scanf(" %s", palavra);
                /* Verifica, caracter por caracter, se a palavra só contém elementos que pertecem ao alfabeto ABMIO */
                /* Se todos os caracteres forem adequados ao alfabeto, o contador terá o mesmo valor que o tamanho da palavra, 
                 * pois todas as verificações de caracter por caracter resultaram em verdadeiras. */
                for (int i = 0; i < strlen(palavra); i++) {

                    if ((palavra[i] == 'A') || (palavra[i] == 'B') || (palavra[i] == 'M') || (palavra[i] == 'I') || (palavra[i] == 'O')) { // Se o caracter for igual a um dos elementos, o resultado é verdadeiro e incrementa-se 'cont'

                        cont++;

                    }
                }

                if (cont == strlen(palavra)) {
                    if (trie_buscaPalavra(palavra, arvore) == 1) {
                        printf("Achamos sua palavra!! aee\n");
                    } else {
                        printf("Palavra não encontrada\n");
                    }
                } else {
                    printf("Existem caracteres não existentes no nosso alfabeto, por favor verifique a palavra digitada e tente novamente\n");
                }
                cont = 0;
                break;
            case 3:
                break;
            case 4:
                break;
        }
    }

    return 0;
}

