#include <stdio.h>

int main() {

    char estado[2], nome_cidade[50], codigo_carta[10];
    int pontos_turisticos;
    float area, pib, densi_populacional, pib_percapita, super_poder, inverso_pop;
    unsigned long int populacao;

    char estado_2[2], nome_cidade_2[50], codigo_carta_2[10];
    int pontos_turisticos_2;
    float area_2, pib_2, densi_populacional_2, pib_percapita_2, super_poder_2, inverso_pop_2;
    unsigned long int populacao_2;

    //Area de entrada de dados

    //carta 1
    printf("Digite a inicial do estado (de'A' a 'H')da carta 1:");
    scanf("%s", &estado);

    printf("Digite o código da carta 1 (uma letra seguida de um número de 01 a 04):");
    scanf("%s", &codigo_carta);

    printf("Digite o nome da cidade:");
    scanf("%s", &nome_cidade);

    printf("Digite o numero de habitantes da cidade:");
    scanf("%lu" , &populacao);

    printf("Digite a area da cidade (em km²");
    scanf("%f", &area);

    printf("Digite o PIB (Produto Interno Bruto) da cidade:");
    scanf("%f", &pib);

    printf("Digite o número de pontos turisticos da cidade:");
    scanf("%d", &pontos_turisticos);

    //Carta2
    printf("Digite a inicial do estado (de'A' a 'H')da carta 2:");
    scanf("%s", &estado_2);

    printf("Digite o código da carta 2 (uma letra seguida de um número de 01 a 04):");
    scanf("%s", &codigo_carta_2);

    printf("Digite o nome da cidade:");
    scanf("%s", &nome_cidade_2);

    printf("Digite o numero de habitantes da cidade:");
    scanf("%lu" , &populacao_2);

    printf("Digite a area da cidade (em km²");
    scanf("%f", &area_2);

    printf("Digite o PIB (Produto Interno Bruto) da cidade:");
    scanf("%f", &pib_2);

    printf("Digite o número de pontos turisticos da cidade:");
    scanf("%d", &pontos_turisticos_2);


    //Caulculo da densidade populacional
    densi_populacional = populacao / area;
    densi_populacional_2 = populacao_2 / area_2;

    //Calculo PIB per Capita
    pib_percapita = pib / populacao;
    pib_percapita_2 = pib_2 / populacao_2;

    //Calculo inverso
    inverso_pop = 1 / densi_populacional;
    inverso_pop_2 = 1 / densi_populacional_2;

    //Calculo do super poder
    super_poder = (float) populacao + area + pib + (float) pontos_turisticos + densi_populacional + pib_percapita + inverso_pop;
    super_poder_2 = (float) populacao_2 + area_2 + pib_2 + (float) pontos_turisticos_2 + densi_populacional_2 + pib_percapita_2 + inverso_pop_2;


    //Area de exibição de dados

    //Carta 1
    printf("\n Carta 1: \n");
    printf("Estado: %s \n", estado);
    printf(" Código: %s \n", codigo_carta);
    printf("Nome da cidade: %s \n ", nome_cidade);
    printf("População: %d \n", populacao);
    printf("Área: %f km² \n", area);
    printf("PIB: %f  \n", pib);
    printf("Número de pontos turísticos: %d \n", pontos_turisticos);
    printf("Densidade populacional: %f \n", densi_populacional);
    printf("PIB per Capita: %f \n", pib_percapita);

    //Carta 2
    printf("\n Carta 2: \n");
    printf("Estado: %s \n", estado_2);
    printf(" Código: %s \n", codigo_carta_2);
    printf("Nome da cidade: %s \n ", nome_cidade_2);
    printf("População: %d \n", populacao_2);
    printf("Área: %f km² \n", area_2);
    printf("PIB: %f \n", pib_2);
    printf("Número de pontos turísticos: %d \n", pontos_turisticos_2);
    printf("Densidade populacional: %f \n", densi_populacional_2);
    printf("PIB per Capita: %f \n", pib_percapita_2);
    printf("Super Poder: %f \n \n", super_poder_2);

    //Comparacao lógica das cartas
    printf("Carta 1 - %s: %d \n", nome_cidade, populacao);
    printf("Carta 2 - %s: %d \n", nome_cidade_2, populacao_2);

    if(populacao > populacao_2){
        printf("Resultado: Carta 1 venceu! \n");
    } else{
        printf("Resultado: Carta 2 venceu! \n");
    }

    return 0;

}
