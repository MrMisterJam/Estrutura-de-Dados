#include <stdlib.h>
#include "pilhampuTAD.h"

struct pilha_mpu {
    mpuTAD *dados[MAX_PILHA_MPU];
    int    topo;  // índice do próximo slot livre
};

pilhaMPU* pilha_mpu_criar(void) {
    pilhaMPU *p = malloc(sizeof(pilhaMPU));
    if (!p) return NULL;
    p->topo = 0;
    return p;
}

void pilha_mpu_destruir(pilhaMPU *p) {
    if (!p) return;
    // destrói todos os sensores ainda na pilha
    while (p->topo > 0) {
        mpuTAD *m = p->dados[--p->topo];
        mpu_destruir(m);
    }
    free(p);
}

int pilha_mpu_vazia(const pilhaMPU *p) {
    return p->topo == 0;
}

int pilha_mpu_cheia(const pilhaMPU *p) {
    return p->topo >= MAX_PILHA_MPU;
}

int pilha_mpu_tamanho(const pilhaMPU *p) {
    return p->topo;
}

int pilha_mpu_push(pilhaMPU *p, mpuTAD *m) {
    if (pilha_mpu_cheia(p)) return 0;
    p->dados[p->topo++] = m;
    return 1;
}

mpuTAD* pilha_mpu_pop(pilhaMPU *p) {
    if (pilha_mpu_vazia(p)) return NULL;
    return p->dados[--p->topo];
}

mpuTAD* pilha_mpu_top(const pilhaMPU *p) {
    if (pilha_mpu_vazia(p)) return NULL;
    return p->dados[p->topo - 1];
}
