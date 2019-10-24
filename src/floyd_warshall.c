// autor: Jardel Carvalho
// ano: 2019

#include "floyd_warshall.h"

float *floyd_warshall(float *m, int N) {
    float *dist = malloc(N * N * sizeof(float));
    if(!dist) {
        return NULL;
    }
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {   
            if(i == j) {
                dist[i + i * N] = 0;
            } else if(m[i + j * N] == 0) {
                dist[i + j * N] = INFINITY;
            } else {
                dist[i + j * N] = m[i + j * N];
            }
        }
    }

    for(int k = 0; k < N; k++) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(dist[i + j * N] > dist[i + k * N] + dist[k + j * N]) {
                    dist[i + j * N] = dist[i + k * N] + dist[k + j * N];
                }
            }
        }
    }

    return dist;
}