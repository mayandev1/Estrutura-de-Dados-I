#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[50];
    int matricula;
    char data[15];
}Aluno;

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

    printf("\n--- Lista ---\n");
    for(int i = 0; i < n; i++){
        printf("%s | %d | %s\n",
               alunos[i].nome,
               alunos[i].matricula,
               alunos[i].data);
    }

    free(alunos);
    return 0;
}