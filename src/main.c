// autor: Jardel Carvalho
// ano: 2019

#include <stdio.h>
#include <stdlib.h>

#include "leitura.h"
#include "floyd_warshall.h"

int main(int argc, char **argv) {
    if(argc != 2) {
        printf("erro: parâmetros insuficientes\n");
    }

    int N;
    float *m = matriz(argv[1], &N);
    printf("mat\n");
    if(!m) {
        printf("erro: problema na leitura do arquivo\n");
    }

    for(int i = 0; i < N * N; i++) {
        printf("%.2f ", m[i]);
        if((i + 1) % N == 0) {
            printf("\n");
        }
    }
    printf("\n\n");

    float *dist = floyd_warshall(m, N);
    printf("dist\n");
    for(int i = 0; i < N * N; i++) {
        printf("%.2f ", dist[i]);
        if((i + 1) % N == 0) {
            printf("\n");
        }
    }
    printf("\n");

    return 0;
}