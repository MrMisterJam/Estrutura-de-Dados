#ifndef _ESCOLA_H
#define _ESCOLA_H
#include <stdbool.h>

typedef struct alunoTCD *alunoTAD;

typedef struct turmaTCD *turmaTAD;

alunoTAD criar_alunoTAD(void);

turmaTAD criar_turmaTAD(void);

void apagar_alunoTAD(alunoTAD *);
void apagar_turmaTAD(turmaTAD *);

void colocar_alunoTurma(turmaTAD, alunoTAD);

bool vazia(turmaTAD);
bool cheia(turmaTAD);

bool aluno_esta_em_turma(turmaTAD, alunoTAD, int*);

void remover_aluno(turmaTAD, alunoTAD);

void trocar_aluno_de_turma(turmaTAD, turmaTAD, alunoTAD);

alunoTAD buscar_aluno_por_nome(turmaTAD, const char*);

#endif