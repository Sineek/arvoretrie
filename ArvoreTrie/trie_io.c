#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"

#define TAMANHO_ALFABETO (6) /* Alfabeto formado pelas letras maiúsculas ABMIO mais um elemento para significar o fim do alfabeto. */
#define TAMANHO_PALAVRA (30)

/* Função que abre um arquivo contendo palavras formadas pelas letras do alfabeto ABMIO e as insere na árvore TRIE */
void trie_gerarArvore(no* arv, char* palavra, char* nomeArqEntrada) {
    FILE* arquivoEnt;
    int i = 0;
    int numPalavras = 0;
    char* vetChavesArv;

    arquivoEnt = fopen(nomeArqEntrada, "r+");

    if (arquivoEnt == NULL) {
        printf("[!] Não foi possível abrir o arquivo \"%s\". \n", nomeArqEntrada);
        break;
    } else {
        // Pega o número de palavras que o arquivo contém pela  leitura da primeira linha do arquivo
        fscanf(arquivoEnt, "%d", numPalavras);

        vetChavesArv = (*char) calloc(numPalavras, sizeof (char));

        // Verifica se foi possível realizar a alocação de espaço para o vetor
        if (vetChavesArv == NULL) {
            printf("[!] Não foi possível alocar memória. \n");
            return NULL;
        } else {
            /* Lê o conteúdo do arquivo e armazena elemento por elemento no vetor, até encontrar o fim do arquivo (EOF - End of File) */
            while ((fscanf(arquivoEnt, " %s\n", (vetChavesArv + i))) != EOF) {
                i++;
            }

            for (i = 0; i < numPalavras; i++) {
                arv = trie_adicionarPalavra(palavra, arv);
            }

        }
    }
    // Dados lidos do arquivo, fecha arquivo.
    fclose(arquivoEnt);

}
