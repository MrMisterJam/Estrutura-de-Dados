#include "escola.h"
#include <stdlib.h>
#include <stdbool.h>
//
// #include "pilha.h"

//

#define TAMMAX 0
#define TAMINI 10

static void aumentar_turma(turmaTAD);

struct alunoTCD
{
    char nome[50];
};

struct turmaTCD
{
    alunoTAD *alunos;
    int contagem;
    int tamanho;
};

alunoTAD criar_alunoTAD(void)
{
    alunoTAD A = malloc(sizeof(struct alunoTCD));
    if (A == NULL)
    {
        return NULL;
    }

    return A;
}

turmaTAD criar_turmaTAD(void)
{
    turmaTAD T = malloc(sizeof(struct turmaTCD));
    if (T == NULL)
    {
        return NULL;
    }
    T->alunos = malloc(sizeof(alunoTAD) * TAMINI);
    if (T->alunos == NULL)
    {
        free(T);
        T = NULL;
        return NULL;
    }
    T->contagem = 0;
    T->tamanho = TAMINI;
    return T;
}

void apagar_alunoTAD(alunoTAD *aluno)
{
    if (*aluno != NULL)
    {
        free(*aluno);
        *aluno = NULL;
    }
}
void apagar_turmaTAD(turmaTAD *turma)
{
    if (*turma != NULL)
    {
        free((*turma)->alunos);
        (*turma)->alunos = NULL;
        free(*turma);
        *turma = NULL;
    }
}

void colocar_alunoTurma(turmaTAD turma, alunoTAD aluno)
{
    if (turma == NULL || aluno == NULL)
    {
        return;
    }
    if (cheia(turma))
    {
        aumentar_turma(turma);
    }
    turma->alunos[turma->contagem++] = aluno;
}

bool cheia(turmaTAD turma)
{
    return turma->contagem == turma->tamanho;
}

static void aumentar_turma(turmaTAD turma)
{
    alunoTAD *temp;
    int novo_tamanho = turma->tamanho * 2;
    temp = realloc(turma->alunos, sizeof(alunoTAD) * novo_tamanho);
    if (temp == NULL)
    {
        exit(1);
    }

    turma->alunos = temp;
    turma->tamanho = novo_tamanho;
}

bool aluno_esta_em_turma(turmaTAD turma, alunoTAD aluno, int *indice)
{
    if (turma == NULL || aluno == NULL)
        return false;
    for (int i = 0; i < turma->contagem; i++)
    {
        if (turma->alunos[i] == aluno)
        {
            if (indice != NULL)
            {
                *indice = i;
            }
            return true;
        }
    }
    return false;
}


void remover_aluno(turmaTAD turma, alunoTAD aluno)
{
    if (turma == NULL || aluno == NULL)
    {
        return;
    }
    if (vazia(turma))
    {
        return;
    }
    int i;
    if (aluno_esta_em_turma(turma, aluno, &i))
    {

        for (int j = i; j < turma->contagem - 1; j++)
        {
            turma->alunos[j] = turma->alunos[j + 1];
        }
        turma->contagem--;
    }
}

void trocar_aluno_de_turma(turmaTAD origem, turmaTAD destino, alunoTAD aluno) {
    if (!aluno_esta_em_turma(origem, aluno, NULL)) return;
    remover_aluno(origem, aluno);
    colocar_alunoTurma(destino, aluno);
}

alunoTAD buscar_aluno_por_nome(turmaTAD turma, const char* nome) {
    for (int i = 0; i < turma->contagem; i++) {
        if (strcmp(turma->alunos[i]->nome, nome) == 0) {
            return turma->alunos[i];
        }
    }
    return NULL;
}