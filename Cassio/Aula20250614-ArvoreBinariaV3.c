#include <stdio.h>
#include <stdlib.h>

#include <windows.h>

struct NO{
  int info;
  struct NO *esq;
  struct NO *dir;
};
typedef struct NO NO;
typedef struct NO* ArvBin;

ArvBin * cria_ArvBin(){
  ArvBin* raiz= (ArvBin*) malloc(sizeof(ArvBin));
  if(raiz!=NULL){
      *raiz = NULL;
  }
  return raiz;
}

//-------------IMPRIMIR------------------
/* Função auxiliar recursiva */
void imprime_NO(struct NO *no, const char *prefixo, int ehUltimo, char lado){
  if(no == NULL){ return;}
  printf("%s", prefixo);
  if(ehUltimo){printf("└── ");
  } else {printf("├── ");}
  if(lado == 'E'){printf("E: ");
  } else if(lado == 'D'){printf("D: ");}
  printf("%d\n", no->info);
  char novoPrefixo[1000];
  snprintf(novoPrefixo,sizeof(novoPrefixo),"%s%s",prefixo,ehUltimo ? "    " : "│   ");
  if(no->esq != NULL){
    imprime_NO(no->esq, novoPrefixo, no->dir == NULL, 'E');
  }
  if(no->dir != NULL){
    imprime_NO(no->dir, novoPrefixo, 1, 'D');
  }
}
/* Função principal de impressão */
void imprime_ArvBin(ArvBin *raiz){
  if(raiz == NULL || *raiz == NULL){
    printf("Árvore vazia.\n");
    return;
  }
  printf("%d\n", (*raiz)->info);
  if((*raiz)->esq != NULL){
    imprime_NO((*raiz)->esq, "", (*raiz)->dir == NULL, 'E');
  }
  if((*raiz)->dir != NULL){
    imprime_NO((*raiz)->dir, "", 1, 'D');
  }
}

//--------------------------

int insere_ArvBin(ArvBin* raiz, int valor){
    if(raiz == NULL){
        return 0;
    }

    NO *novo = (NO*) malloc(sizeof(NO));
    if(novo == NULL){
        return 0;
    }
    novo->info = valor;
    novo->esq =NULL;
    novo->dir =NULL;

    if(*raiz == NULL){//primeiro elemento
        *raiz = novo;
    }
    else{//folha
        NO *atual = *raiz;
        NO *ant = NULL;
        while(atual!=NULL){
            ant = atual;
            if(valor==atual->info){//repetido
                free(novo);
                return 0;
            }
            if(valor>atual->info){
                atual = atual->dir;
            }else{
                atual = atual->esq;
            }
        }
        if(valor>ant->info){
            ant->dir = novo;
        }else{
            ant->esq = novo;
        }
    }
    return 1;
}

int consulta_ArvBin(ArvBin *raiz, int valor){
    if(raiz == NULL){ return 0;}
    if(*raiz == NULL){ return 0;}
    else{
        NO *atual = *raiz;
        while(atual!=NULL){
            if(valor==atual->info){return 1;}
            if(valor>atual->info){atual = atual->dir;
            }else{atual = atual->esq;}
        }
    }
    return 0;
}

int totalNosArvBin(ArvBin* raiz){
    if(raiz == NULL){ return 0;}
    if(*raiz == NULL){ return 0;}

    int nos_esq = totalNosArvBin(&((*raiz)->esq));
    int nos_dir = totalNosArvBin(&((*raiz)->dir));

    return nos_esq+nos_dir+1;
}

int altura_ArvBin(ArvBin* raiz){
    if(raiz == NULL){ return -1;}
    if(*raiz == NULL){ return -1;}

    int alt_esq = altura_ArvBin(&((*raiz)->esq));
    int alt_dir = altura_ArvBin(&((*raiz)->dir));

    if(alt_esq>alt_dir){
        return(alt_esq+1);
    }else{
        return(alt_dir+1);
    }

    return 1;
}



void preOrdem_arvBin(ArvBin *raiz){
    if(raiz==NULL){
        return;
    }
    if(*raiz != NULL){
        printf("%d\t", (*raiz)->info);
        preOrdem_arvBin(&((*raiz)->esq));
        preOrdem_arvBin(&((*raiz)->dir));
    }
}

void emOrdem_arvBin(ArvBin *raiz){
    if(raiz==NULL){
        return;
    }
    if(*raiz != NULL){
        preOrdem_arvBin(&((*raiz)->esq));
        printf("%d\t", (*raiz)->info);
        preOrdem_arvBin(&((*raiz)->dir));
    }
}

void posOrdem_arvBin(ArvBin *raiz){
    if(raiz==NULL){
        return;
    }
    if(*raiz != NULL){
        preOrdem_arvBin(&((*raiz)->esq));
        preOrdem_arvBin(&((*raiz)->dir));
        printf("%d\t", (*raiz)->info);
    }
}



NO* remove_atual(NO *atual){
    NO *no1, *no2;

    if(atual->esq ==NULL){
        no2 = atual->dir;
        free(atual);
        return no2;
    }

    no1 = atual;
    no2 = atual->esq;

    while(no2->dir !=NULL){
        no1 = no2;
        no2 = no2->dir;
    }

    if(no1 != atual){
        no1->dir = no2->esq;
        no2->esq = atual->esq;
    }

    no2->dir = atual->dir;
    free(atual);

    return no2;
}

int removeArvoreBin(ArvBin *raiz, int valor){
    if(raiz == NULL){
        return 0;
    }

    NO *ant = NULL;
    NO *atual = *raiz;

    while(atual!=NULL){
        if(valor == atual->info){
            if(atual == *raiz){
                *raiz = remove_atual(atual);
            }
            else{
                if(ant->dir == atual){
                    ant->dir = remove_atual(atual);
                }else{
                    ant->esq = remove_atual(atual);
                }

            }
        }
        //anda na arvore
        ant = atual;
        if(valor>atual->info){
            atual = atual->dir;
        }else{
            atual = atual->esq;
        }
    }
    return 0;

}

int main(void) {
  SetConsoleOutputCP(65001);
  ArvBin* raiz = cria_ArvBin();
  int N = 10,dados[10] = {28,16,40,11,21,36,48,19,32,56};
  for(int i=0;i<N;i++){
    insere_ArvBin(raiz, dados[i]);
  }

  int altura = altura_ArvBin(raiz);
  printf("\nAltura: %d ",altura);
  int quantidade = totalNosArvBin(raiz);
  printf("\nQuantidade: %d ",quantidade);

  printf("\nPréOrdem:");
  preOrdem_arvBin(raiz);
  printf("\nEmOrdem:");
  emOrdem_arvBin(raiz);
  printf("\nPosOrdem:");
  posOrdem_arvBin(raiz);
  printf("\nFinalizou.\n");

  imprime_ArvBin(raiz);
  return 0;
}
