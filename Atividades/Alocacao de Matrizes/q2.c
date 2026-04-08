#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **alocar_matriz(int linhas, int colunas){
    int **matriz;

    matriz = (int**) malloc(linhas * sizeof(int*));
    if (matriz == NULL){
        printf("Erro de aloc\n");
        exit(1);
    }

    for (int i = 0; i < linhas; i++){
        matriz[i] = (int*) calloc(colunas, sizeof(int));
        if (matriz[i] == NULL){
            printf("Erro de alocacao");
            exit(1);
        } 
    }

    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            matriz[i][j] = rand() % 200;
        }
    }
    
    return matriz;
}

void mostrarMatriz(int **mat, int linhas, int colunas){
    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

float calcular_media(int **mat, int linhas, int colunas){
    int soma = 0;
    float media = 0, count = 0;
    
    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            soma += mat[i][j];
            count++;
        }
    }

    return media = soma/count;
}

int calcular_diagonal_principal(int **mat, int linhas, int colunas){
    int soma = 0;
    
    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            if (i == j){
                soma += mat[i][j];
            }
        }
    }

    return soma;
}

void free_aloc(int **mat, int linhas){
    for (int i = 0; i < linhas; i++){
        free(mat[i]);
    }
    free(mat);
}

int main(){
    int **matriz, linhas, colunas, soma = 0;
    float media = 0;

    printf("Digite a quantidade de linhas e colunas:\n");
    scanf("%d%d", &linhas, &colunas);

    matriz = alocar_matriz(linhas, colunas);
    mostrarMatriz(matriz, linhas, colunas);

    media = calcular_media(matriz, linhas, colunas);
    printf("Media dos valores da matriz: %.2f\n", media);

    soma = calcular_diagonal_principal(matriz, linhas, colunas);
    printf("Soma da diagonal principal: %d\n", soma);

    free_aloc(matriz, linhas);

    return 0;
}
