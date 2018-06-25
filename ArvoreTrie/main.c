#include <stdio.h>
#include <stdlib.h>

int main() {
    int escolha = 0;
    
    while (escolha != 3) {
        printf("[1] Gerar trie\n");
        printf("[2] Testar aplicação\n");
        printf("[3] Sair\n");
        scanf("%d", &escolha);
    }
    switch (escolha) {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
    }

    return 0;
}

