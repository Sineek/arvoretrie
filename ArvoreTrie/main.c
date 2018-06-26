#include <stdio.h>
#include <stdlib.h>
#include "trie.h"
#include "trie_io.h"

int main() {
    int escolha = 0;
    no* arvore;  
    char nomeArquivoEnt[51];
    
    arvore = trie_criarNo(); 
    
    while (escolha != 3) {
        printf("[1] Gerar trie; \n");
        printf("[2] Testar aplicação; \n");
        printf("[3] Sair. \n");
        scanf("%d", &escolha);
    }
    switch (escolha) {
        case 1:
            printf("Digite o nome do arquivo que contém as palavras: ");
            scanf(" %50[^\n]", nomeArquivoEnt); // Lê o nome do arquivo de entrada de dados.
          
            trie_gerarArvore(arvore, nomeArquivoEnt); 
            break;
        case 2:
            break;
        case 3:
            break;
    }

    return 0;
}

