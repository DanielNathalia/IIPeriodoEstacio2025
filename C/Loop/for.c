#include <stdio.h>

int main(){

    int num, i;

    printf("Digite um numero para calcularmos a tabuada:");
    scanf("%d", &num);
    for(i = 0; i <=10; i++){
        printf("%d * %d = %d \n", i, num, i*num);
    }


    return 0;
}
