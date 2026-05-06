#include <stdio.h>

int main(){
    //int i = 1, j = 1;

      // Movimentação da Torre
    printf("Movimentacao da Torre:\n");
    for (int i = 1; i <= 5; i++) {
        printf("Direita\n");
    }
    printf("\n");

    // Movimentação do Bispo
    printf("Movimentacao do Bispo:\n");
    int i = 1;
    while (i <= 5) {
        printf("Cima, Direita\n");
        i++;
    }
    printf("\n");

    // Movimentação da Rainha
    printf("Movimentacao da Rainha:\n");
    int j = 1;
    do {
        printf("Esquerda\n");
        j++;
    } while (j <= 8);
    printf("\n");

    //Movimentação do Cavalo

    // Declaração de variáveis para as movimentações
    const int movimentoBaixo = 2;
    const int movimentoEsquerda = 1;

    // Movimentação para baixo
    printf("\nMovimento do Cavalo:\n");
    for (int i = 1; i <= movimentoBaixo; i++) {
        printf("Baixo\n");
    }
    // Movimentação para a esquerda
    int k = 1;
    while (k <= movimentoEsquerda) {
        printf("Esquerda\n");
        k++;
    }
    // Mensagem ao final
    printf("\nMovimentação concluída.\n");

    return 0;
}
