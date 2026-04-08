#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int linhas = 5, colunas = 5;

    int **mat;

    mat = (int**) malloc(linhas * sizeof(int*));

    for(int i = 0; i < linhas; i++){
        mat[i] = (int*) malloc(colunas * sizeof(int));
    }

    srand(time(NULL));

    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            mat[i][j] = rand() % 100;
        }
    }

    printf("\nMatriz:\n");
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < linhas; i++){
        free(mat[i]);
    }
    free(mat);

    return 0;
}