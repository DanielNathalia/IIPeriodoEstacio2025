#include <stdio.h>

int main() {

    // Definio das variveis para o movimento
    const int movimentoCima = 2; // Duas casas para cima
    const int movimentoDireita = 1; // Uma casa para a direita
    int passosRealizados = 0; // Contador total de passos

    printf("\nMovimento do Cavalo:\n");

    // Loop externo (controle do movimento completo)
    for (int i = 1; i <= movimentoCima + movimentoDireita; i++) {
        // Condi��o para determinar se o passo � vertical ou horizontal
        if (i <= movimentoCima) {
            printf("Cima\n"); // Movimento para cima
            passosRealizados++;
        } else {
            for (int j = 0; j < movimentoDireita; j++) {
                printf("Direita\n"); // Movimento para a direita
                passosRealizados++;
            }
            break; // Finaliza o loop ap�s o movimento horizontal
        }

        // Condi��o para interromper ap�s completar todos os passos
        if (passosRealizados == (movimentoCima + movimentoDireita)) {
            break;
        }
    }

    // Mensagem final indicando o t�rmino do movimento
    printf("\nMovimenta��o do Cavalo conclu�da.\n");

    return 0;
}
