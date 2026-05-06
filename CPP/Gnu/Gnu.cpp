/*********************************\
 2 * *
 3 * COMPILAR COM PARÂMETRO -pthread *
 4 * *
 5 \*********************************/
 
 #define _GNU_SOURCE
 #include <stdio.h>
 #include <stdlib.h>
#include <unistd.h>
#include <sched.h>
#include <sys/wait.h>
#include <semaphore.h>

#define TAMANHO_PILHA 65536

sem_t mutex; // Cria semáforo mutex

void up(sem_t *sem) {
    sem_wait(sem);
}

void down(sem_t *sem) {
    sem_post(sem);
}

typedef struct {
    double saldo;
} Registro;

Registro registro;

Registro le_registro(int conta){
    return registro;
 }

void grava_registro(Registro reg, int conta){
    registro = reg;
}

void atualiza_saldo(double valor, int conta) {
    Registro registro;
    up(&mutex);
    printf("Iniciando operação [%.2f]\n", valor);
    registro = le_registro(conta);
    usleep(1000);
    registro.saldo = registro.saldo + valor;
    grava_registro(registro, conta);
    printf("Terminada operação [%.2f]\n", valor);
    down(&mutex);
}

int funcaoDeposito(void *arg) {
    // Faz deposito de 100,00
    atualiza_saldo(100, 0);
}

int funcaoSaque(void *arg) {
    // Faz saque de 200,00
    atualiza_saldo(-200, 0);
}

int main() {
    void *pilha1, *pilha2;
    int pid1, pid2;

    // Inicializa mutex om valor 1 (somente um thread na região crítica)
    sem_init(&mutex, 1, 1);
    
    registro.saldo = 500; // Inicializa saldo
    printf("Saldo antes das operações = %.2f\n", registro.saldo);

    // Aloca pilha para thread de depósito
    if ((pilha1 = malloc(TAMANHO_PILHA)) == 0) {
        perror("Erro na alocação da pilha.");
        exit(1);
    }
    // Inicia thread de depósito
    pid1 = clone(funcaoDeposito,
            pilha1 + TAMANHO_PILHA,
            CLONE_VM | CLONE_FS | CLONE_FILES | CLONE_SIGHAND | SIGCHLD,
            NULL);

     // Aloca pilha para thread de saque
    if ((pilha2 = malloc(TAMANHO_PILHA)) == 0) {
        perror("Erro na alocação da pilha.");
        exit(1);
    }
    // Inicia thread de saque
    pid2 = clone(funcaoSaque,
            pilha2 + TAMANHO_PILHA,
            CLONE_VM | CLONE_FS | CLONE_FILES | CLONE_SIGHAND | SIGCHLD,
            NULL);

    //Aguarda final da operações
    waitpid(pid1, 0, 0);
    waitpid(pid2, 0, 0);

    printf("Saldo depois das operações = %.2f\n", registro.saldo);
}
