#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[50];
    int idade, matricula;
} Aluno;

int main(){
    Aluno *classe;
    int n_alunos;

    printf("Quantos alunos ha na classe?\n");
    scanf("%d", &n_alunos);

    classe = (Aluno*) malloc(n_alunos * sizeof(Aluno));
    if (classe == NULL){
        printf("ERRO DE ALOCACAO!\n");
        exit(1);
    }
    
    for (int i = 0; i < n_alunos; i++){
        printf("Nome:\n");
        scanf("%s", classe[i].nome);
        printf("Idade e matricula:\n");
        scanf("%d%d", &classe[i].idade, &classe[i].matricula);
    }

    for (int i = 0; i < n_alunos; i++){
        printf("Nome: %s || Idade: %d || Matricula: %d\n", classe[i].nome, classe[i].idade, classe[i].matricula);
    }
    
    free(classe);
    return 0;
}