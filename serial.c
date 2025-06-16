#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define largura_matriz 800 //aqui vc define a largura que quer que sua matriz tenha
#define altura_matriz 800 // e aqui, a altura

int ehPrimo(int n){
    if (n < 2){
        return 0;
    }
    int i = 2;
    while (i <= (int)sqrt(n)){
        if (n % i == 0){
            return 0; //aqui retorna False porque achou divisor
        }
        i++;
    }
    return 1; // True se não achou divisor
}

//inicializando e printando a matriz
void imprimirMatriz (int matriz[altura_matriz][largura_matriz]){
    printf("A matriz eh: \n");
    for (int i = 0; i < altura_matriz; i++){
        for (int j = 0; j < largura_matriz; j++){
            matriz[i][j] = rand() % 4000;
            printf(" %4d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int contaPrimos(int matriz[altura_matriz][largura_matriz]){
    int n_primos = 0;
    printf("\nNumeros primos encontrados na matriz:\n");
    for (int altura = 0; altura < altura_matriz; altura++){
        for (int largura = 0; largura < largura_matriz; largura++){
            int n = matriz[altura][largura];
            if (ehPrimo(n)){
                n_primos++;
                printf("%d\n", n);
            }
        }
    }
    return n_primos;
}

int main() {
    int matriz_principal[altura_matriz][largura_matriz];

    srand(time(NULL)); //gera numeros aleatorios

    clock_t inicio = clock(); //inicio da contagem de tempo de compilacao

    imprimirMatriz(matriz_principal);
    int n_primos = contaPrimos(matriz_principal);

    clock_t fim = clock(); //fim da contagem de tempo de compilacao

    double duracao_exec = (double) (fim - inicio) / CLOCKS_PER_SEC;

    printf("\nTotal de primos encontrados: %d\n", n_primos);
    printf("\nO tempo total de execucao foi de: %.6f segundos", duracao_exec);

    return 0;
}