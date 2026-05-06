#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_TABULEIRO 15 // Define o tamanho do tabuleiro

void criarMatrizCone(int tamanho, int matriz[tamanho][tamanho]) {
    int centro = tamanho / 2;
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            matriz[i][j] = (j >= centro - i && j <= centro + i) ? 1 : 0;
        }
    }
}

void criarMatrizCruz(int tamanho, int matriz[tamanho][tamanho]) {
    int centro = tamanho / 2;
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            matriz[i][j] = (i == centro || j == centro) ? 1 : 0;
        }
    }
}

void criarMatrizOctaedro(int tamanho, int matriz[tamanho][tamanho]) {
    int centro = tamanho / 2;
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            int distancia = abs(i - centro) + abs(j - centro);
            matriz[i][j] = (distancia <= centro) ? 1 : 0;
        }
    }
}

void integrarHabilidadeAoTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],
                                   int habilidade[][7], int tamanhoHabilidade, int origemX, int origemY) {
    int inicioX = origemX - tamanhoHabilidade / 2;
    int inicioY = origemY - tamanhoHabilidade / 2;

    for (int i = 0; i < tamanhoHabilidade; i++) {
        for (int j = 0; j < tamanhoHabilidade; j++) {
            int x = inicioX + i;
            int y = inicioY + j;

            if (x >= 0 && x < TAMANHO_TABULEIRO && y >= 0 && y < TAMANHO_TABULEIRO && habilidade[i][j] == 1) {
                tabuleiro[x][y] = 5; // Marca as áreas afetadas pela habilidade com o valor 5
            }
        }
    }
}

void imprimirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    memset(tabuleiro, 0, sizeof(tabuleiro)); // Inicializa o tabuleiro com 0

    int matrizCone[7][7];
    int matrizCruz[7][7];
    int matrizOctaedro[7][7];

    // Criação das matrizes de habilidade
    criarMatrizCone(7, matrizCone);
    criarMatrizCruz(7, matrizCruz);
    criarMatrizOctaedro(7, matrizOctaedro);

    // Integração das habilidades no tabuleiro
    integrarHabilidadeAoTabuleiro(tabuleiro, matrizCone, 7, 4, 4);     // Exemplo: Cone no ponto (4,4)
    integrarHabilidadeAoTabuleiro(tabuleiro, matrizCruz, 7, 10, 10);  // Exemplo: Cruz no ponto (10,10)
    integrarHabilidadeAoTabuleiro(tabuleiro, matrizOctaedro, 7, 7, 7); // Exemplo: Octaedro no ponto (7,7)

    // Imprime o tabuleiro resultante
    printf("Tabuleiro com habilidades integradas:\n");
    imprimirTabuleiro(tabuleiro);

    return 0;
}
