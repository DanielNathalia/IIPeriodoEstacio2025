#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int opcao;
    int numeroSecreto, palpite;

    printf("Menu principal\n");
    printf("1. Iniciar o jogo\n");
    printf("2. Ver regras\n");
    printf("3. Sair\n");
    printf("Escolha uma opção:\n");
    scanf("%d", &opcao);

    switch(opcao){
    case 1:
        srand(time(0));
        numeroSecreto = rand() % 10 + 1;
        printf("Digite um número de 0 a 9: \n");
        scanf("%d", &palpite);
        if(numeroSecreto == palpite){
            printf("Você acertou! \n");
            printf("Numero secreto: %d \n", &numeroSecreto);
        } i{
            printf("Você errou! \n");
            printf("Numero secreto: %d \n", &numeroSecreto);
        }
    break;
    case 2:
         printf("Regras do Jogo:\n");
        printf("1. Escolha uma opção no menu.\n");
        printf("2. Se você escolher 'Iniciar Jogo', adivinhe o número secreto.\n");
        printf("3. O jogo termina quando você escolhe 'Sair'.\n");
    break;
    case 3:
        printf("Saindo do jogo");
    break;
    default:
        printf("Opçao invalida! \n");
    }
    return 0;
}
