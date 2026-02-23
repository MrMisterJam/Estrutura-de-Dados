#ifndef PILHAMPU_TAD_H
#define PILHAMPU_TAD_H

#include "mpuTAD.h"

#define MAX_PILHA_MPU 100

typedef struct pilha_mpu pilhaMPU;

/* Cria e destrói a pilha */
pilhaMPU*  pilha_mpu_criar(void);
void       pilha_mpu_destruir(pilhaMPU *p);

/* Consultas de estado */
int        pilha_mpu_vazia(const pilhaMPU *p);
int        pilha_mpu_cheia(const pilhaMPU *p);
int        pilha_mpu_tamanho(const pilhaMPU *p);

/* Operações de empilhar/desempilhar */
/* Retorna 1 em sucesso, 0 se cheia */
int        pilha_mpu_push(pilhaMPU *p, mpuTAD *m);
/* Retorna o ponteiro para o sensor desempilhado, ou NULL se vazia */
mpuTAD*    pilha_mpu_pop(pilhaMPU *p);
/* Retorna o ponteiro para o sensor no topo, ou NULL se vazia */
mpuTAD*    pilha_mpu_top(const pilhaMPU *p);

#endif // PILHAMPU_TAD_H
