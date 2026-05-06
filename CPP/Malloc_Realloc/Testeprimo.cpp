#include <stdio.h>
#include <stdlib.h>


int main() {
    int *primos = (int *) malloc(sizeof(int));
    if (primos == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    int contador = 0;
    int numero = 2;

    while (contador < 100) {
        if (ehPrimo(numero)) {
            primos = (int *) realloc(primos, (contador + 1) * sizeof(int));
            if (primos == NULL) {
                printf("Erro ao realocar memória.\n");
                return 1;
            }
            primos[contador] = numero;
            contador++;
        }
        numero++;
    }

    printf("O 100º número primo é: %d\n", primos[99]);

    free(primos); // libera a memória alocada
    return 0;
}




