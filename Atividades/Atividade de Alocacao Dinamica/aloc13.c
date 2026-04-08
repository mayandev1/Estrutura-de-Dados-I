#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[50];
    int matricula;
    char data[15];
}Aluno;

Aluno* buscar(Aluno *v, int n, char nome[]){
    for(int i = 0; i < n; i++){
        if(strcmp(v[i].nome, nome) == 0){
            return &v[i];
        }
    }
    return NULL;
}

void editar(Aluno *a){
    if(a == NULL){
        printf("Aluno nao encontrado!\n");
        return;
    }

    printf("\n--- Editando aluno ---\n");

    printf("Novo nome: ");
    scanf(" %[^\n]", a->nome);

    printf("Nova matricula: ");
    scanf("%d", &a->matricula);

    printf("Nova data nascimento: ");
    scanf(" %[^\n]", a->data);
}

int main(){
    int n;

    printf("Quantidade de alunos: ");
    scanf("%d", &n);

    Aluno *alunos = (Aluno*) malloc(n * sizeof(Aluno));

    for(int i = 0; i < n; i++){
        printf("\nAluno %d\n", i+1);

        printf("Nome: ");
        scanf(" %[^\n]", alunos[i].nome);

        printf("Matricula: ");
        scanf("%d", &alunos[i].matricula);

        printf("Data nascimento: ");
        scanf(" %[^\n]", alunos[i].data);
    }

    char nomeBusca[50];
    printf("\nDigite o nome para buscar: ");
    scanf(" %[^\n]", nomeBusca);

    Aluno *encontrado = buscar(alunos, n, nomeBusca);
    editar(encontrado);

    printf("\n--- Lista Atualizada ---\n");
    for(int i = 0; i < n; i++){
        printf("%s | %d | %s\n",
               alunos[i].nome,
               alunos[i].matricula,
               alunos[i].data);
    }

    free(alunos);
    return 0;
}