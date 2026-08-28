/*
Uma instituição de ensino possui um arquivo texto denominado alunos.txt, contendo registros de alunos
no seguinte formato:

id;matricula;nome;media

1;2026001;Ana Silva;5.1

2;2026002;Bruno Souza;5.2

...

Deseja-se desenvolver um sistema para armazenar essas informações em um arquivo binário,
permitindo consultas eficientes aos registros.

Considere a seguinte estrutura:

typedef struct {
    int id;
    int matricula;
    char nome[40];
    float media;
} Aluno;


    a) Implemente uma função que:

    Abra o arquivo texto fornecido.

    Leia todos os registros de alunos.

    Crie um arquivo binário chamado alunos.dat.

    Grave cada registro utilizando a função fwrite.

    Exiba ao final a quantidade de registros gravados.


    b) Implemente uma função que:

    Solicite ao usuário uma matrícula.

    Percorra o arquivo binário utilizando leitura sequencial com fread.

    Localize o aluno cuja matrícula foi informada.

    Exiba:

    ID

    Matrícula

    Nome

    Média

    Quantidade de registros lidos durante a busca

Caso a matrícula não exista, informe que o aluno não foi encontrado.

    c)

    Sabendo que os registros possuem tamanho fixo, implemente uma função que:

    Solicite ao usuário um RRN (Relative Record Number).

    Posicione diretamente o ponteiro de arquivo utilizando fseek.

    Recupere o registro correspondente com fread.

    Exiba todas as informações do aluno encontrado.

Considere que:

    O primeiro registro possui RRN igual a 0.

    O arquivo contém exatamente 100 registros.


    d) Implemente uma funcionalidade que permita alterar a média de um aluno diretamente no arquivo
    binário utilizando o RRN, sem recarregar todos os registros para a memória.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    int id;
    int matricula;
    char nome[40];
    float media;
} Aluno;

void gerar_binario(char *txt);

void buscar_aluno();

void criar_alunostxt();

void exibir_aluno(Aluno temp);

void buscar_registro();

void alterar_media();

int main(void)
{
    //criar_alunostxt();
    //gerar_binario("alunos.txt");
    buscar_aluno();
    //buscar_registro();
    //alterar_media();
    return 0;
}

void gerar_binario(char *txt)
{
    FILE *arquivo_txt, *arquivo_binario;
    int contagem = 0;
    Aluno temp;
    arquivo_txt = fopen(txt, "r");
    if (arquivo_txt == NULL)
    {
        printf("Arquivo nao pode ser encontrado. Encerrando programa.");
        exit(1);
    }
    arquivo_binario = fopen("alunos.dat", "wb");
    if (arquivo_binario == NULL)
    {
        printf("Nao foi possivel criar o arquivo binario.");
        fclose(arquivo_txt);
        exit(1);
    }
    while (fscanf(arquivo_txt, "%i;%i;%49[^;];%f",
                  &temp.id,
                  &temp.matricula,
                  temp.nome,
                  &temp.media) == 4)
    {
        fwrite(&temp, sizeof(Aluno), 1, arquivo_binario);
        contagem++;
    }
    fclose(arquivo_txt);
    fclose(arquivo_binario);
    printf("Arquivo binario criado com %i registros.\n", contagem);
}

void buscar_aluno()
{
    FILE *f;
    int FOUND = 0, contagem = 0, matricula;
    Aluno temp;
    f = fopen("alunos.dat", "rb");
    if (f == NULL)
        exit(1);
    printf("\nBUSCAR ALUNO\n\nDigite a matricula do aluno que deseja buscar: ");
    scanf("%i", &matricula);
    while (fread(&temp, sizeof(temp), 1, f) == 1)
    {
        contagem++;
        if (temp.matricula == matricula)
        {
            exibir_aluno(temp);
            FOUND = 1;
            break;
        }
    }
    fclose(f);
    if (!FOUND)
        printf("Matricula nao encontrada.\n");
    printf("Contagem de dados lidos: %i\n", contagem);
}

void criar_alunostxt()
{
    FILE *file;
    int n, i;
    printf("Quantos alunos deseja criar? ");
    scanf("%i", &n);
    Aluno alunos[n];

    // Obter alunos
    for (i = 0; i < n; i++)
    {
        printf("Aluno %i\nDigite o nome do aluno: ", i + 1);
        getchar();
        fgets(alunos[i].nome, sizeof(alunos[i].nome), stdin);
        printf("Digite a matricula do aluno: ");
        scanf("%i", &alunos[i].matricula);
        printf("Digite a media do aluno: ");
        scanf("%f", &alunos[i].media);
        alunos[i].id = i + 1;
        alunos[i].nome[strcspn(alunos[i].nome, "\n")] = '\0';
    }

    // Imprimir alunos
    file = fopen("alunos.txt", "a");
    for (i = 0; i < n; i++)
    {
        fprintf(file, "%i;%i;%s;%f\n", alunos[i].id, alunos[i].matricula, alunos[i].nome, alunos[i].media);
    }
    fclose(file);
}

void exibir_aluno(Aluno temp)
{
    printf("\nID: %i\nMatricula: %i\nNome: %s\nMedia: %.1f\n",
           temp.id, temp.matricula, temp.nome, temp.media);
}

void buscar_registro()
{
    FILE *f;
    int pos;
    Aluno temp;
    f = fopen("alunos.dat", "rb");
    if (f == NULL)
        exit(1);
    printf("\nBUSCA DE REGISTRO\nDigite o RRN do registro:\n");
    scanf("%i", &pos);
    if (pos >= 100 || pos < 0)
    {
        printf("Limite ultrapassado de registros.\n");
        fclose(f);
        exit(1);
    }
    if (fseek(f, pos * sizeof(Aluno), 0))
        printf("Registro nao encontrado.\n");
    else
    {
        fread(&temp, sizeof(Aluno), 1, f);
        exibir_aluno(temp);
    }
    fclose(f);
}

void alterar_media()
{
    FILE *f;
    int pos;
    Aluno temp;
    f = fopen("alunos.dat", "rb+");
    if (f == NULL)
        exit(1);
    printf("\nALTERAR MEDIA\nDigite o RRN do registro:\n");
    scanf("%i", &pos);
    if (pos >= 100 || pos < 0)
    {
        printf("Limite ultrapassado de registros.\n");
        fclose(f);
        return;
    }
    if (fseek(f, pos * sizeof(Aluno), 0))
    {
        printf("Registro nao encontrado.\n");
        fclose(f);
        return;
    }
    if (fread(&temp, sizeof(Aluno), 1, f) != 1)
    {
        printf("Registro nao encontrado.\n");
        fclose(f);
        return;
    }

    printf("Aluno encontrado:\n");
    exibir_aluno(temp);

    printf("Digite a nova media:\n");
    scanf("%f", &temp.media);

    fseek(f, -sizeof(Aluno), SEEK_CUR);

    if (fwrite(&temp, sizeof(Aluno), 1, f) != 1)
        printf("Erro ao alterar o registro.\n");
    else
        printf("Media alterada com sucesso.\n");

    fclose(f);
}
