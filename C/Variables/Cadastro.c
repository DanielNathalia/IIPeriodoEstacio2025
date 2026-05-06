#include <stdio.h>

int main(){

    char nome[50];
    int idade, matricula;
    float altura;

    printf("Digite a sua idade: \n");
    scanf("%d", &idade);

    printf("Digite sua altura: \n");
    scanf("%f", &altura);

    printf("Digite o seu nome: \n");
    scanf("%s", &nome);

    printf("Digite sua matricula: \n");
    scanf("%d", &matricula);

    printf("Nome do aluno: %s - Matricula: %d\n", nome, matricula);
    printf("Idade do aluno: %d - Altura: %f", idade, altura);

    return 0;

}
