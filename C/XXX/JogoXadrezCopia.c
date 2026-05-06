#include <stdio.h>


// Movimentação da Torre
void movimentoTorre(int torre){
    if(torre > 0){
        printf("Direita \n", torre);
        movimentoTorre(torre - 1);
    }

}

// Movimentação da Rainha
void movimentoRainha(int rainha){
    if(rainha > 0){
        movimentoRainha(rainha - 1);
        printf("Esquerda \n", rainha);
    }
}

int main (){
    int torre = 5, bispo = 5, rainha = 8;

    printf("***JOGO DE XADREZ***\n");
    printf("\n");
    printf("Movimento da Torre: \n");
    movimentoTorre(torre);
    printf("\n");
    printf("Movimento da Rainha: \n");
    movimentoRainha(rainha);


    //Movimentação do Bispo

    // Definição do número de casas que o Bispo deve se mover
    const int cima = 5; // Número de casas para cima
    const int direita = 1; // Número de casas para a direita

    printf("\nMovimento do Bispo:\n");

    // Loop externo (Cima)
    for (int i = 1; i <= cima; i++) {
        printf("Cima \n");
        // Loop interno (Direita)
        for (int j = 1; j <= direita; j++) {
            printf("Direita \n");
        }
    }

    //Movimentação do Cavalo

    // Definição das variáveis para o movimento
    const int movimentoCima = 2; // Duas casas para cima
    const int movimentoDireita = 1; // Uma casa para a direita
    int passosRealizados = 0; // Contador total de passos

    printf("\nMovimento do Cavalo:\n");

    // Loop externo (controle do movimento completo)
    for (int i = 1; i <= movimentoCima + movimentoDireita; i++) {
        // Condição para determinar se o passo é vertical ou horizontal
        if (i <= movimentoCima) {
            printf("Cima\n"); // Movimento para cima
            passosRealizados++;
        } else {
            for (int j = 0; j < movimentoDireita; j++) {
                printf("Direita\n"); // Movimento para a direita
                passosRealizados++;
            }
            break; // Finaliza o loop após o movimento horizontal
        }

        // Condição para interromper após completar todos os passos
        if (passosRealizados == (movimentoCima + movimentoDireita)) {
            break;
        }
    }
    // Mensagem ao final
    printf("\nMovimentação concluída.\n");

    return 0;
}
