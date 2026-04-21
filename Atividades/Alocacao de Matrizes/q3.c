#include <stdio.h>
#include <stdlib.h>

float **alocar_matriz(int alunos, int notas){
    float **mat;

    mat = (float**) malloc(alunos * sizeof(float*));
    if (mat == NULL){
        return NULL;
    }
    
    for (int i = 0; i < alunos; i++){
        mat[i] = (float*) calloc(notas, sizeof(float));
        if (mat[i] == NULL){
            return NULL;
        }
    }
    
    return mat;
}

void preencher_notas(float **mat, int alunos, int notas){
    for (int i = 0; i < alunos; i++){
        printf("Digite as notas do aluno %d:\n", i+1);
        for (int j = 0; j < notas; j++){
            scanf("%f", &mat[i][j]);
        }
    }
}

void calcular_media(float **mat, int alunos, int notas){
    for (int i = 0; i < alunos; i++){
        float soma = 0;
        for (int j = 0; j < notas; j++){
            soma += mat[i][j];
        }
        
        float media = soma/notas;

        printf("Media do aluno %d: %.2f\n", i+1, media);
    }
}

int main(){
    int alunos, notas;
    float **mat;

    printf("Digite a quantidade de alunos e notas:\n");
    scanf("%d%d", &alunos, &notas);

    mat = alocar_matriz(alunos, notas);
    preencher_notas(mat, alunos, notas);
    calcular_media(mat, alunos, notas);

    for (int i = 0; i < alunos; i++){
        free(mat[i]);
    }
    free(mat);

    return 0;
}
