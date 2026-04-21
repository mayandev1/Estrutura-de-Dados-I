#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **alocar_matriz(int linha, int coluna){
    int **mat;

    mat = (int**) malloc(linha * sizeof(int*));
    if (mat == NULL){
        printf("ERRO DE ALOC!\n");
        exit(1);
    }

    for (int i = 0; i < linha; i++){
        mat[i] = (int*) calloc(coluna, sizeof(int));
        if (mat[i] == NULL){
            printf("ERRO DE ALOC!\n");
            exit(1);
        }
    }
    
    return mat;
}

void liberar_memoria(int **mat, int linhas){
    for (int i = 0; i < linhas; i++){
        free(mat[i]);
    }
    
    free(mat);
}

void preencher_matriz(int **mat, int linhas, int colunas){
    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            mat[i][j] = rand() % 10;
        }
    }
}

void soma_superior_inferior(int **mat, int linhas, int colunas){
    int somaSup = 0, somaInf = 0;

    for (int i = 0; i < linhas; i++){
        for (int j = i + 1; j < colunas; j++){
            somaSup += mat[i][j];
        }
    }

    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < i; j++){  
            somaInf += mat[i][j];
        }
    }

    printf("Soma superior a diagonal principal: %d\n", somaSup);
    printf("Soma inferior a diagonal principal: %d\n", somaInf);

    if (somaSup > somaInf){
        printf("Soma maior foi a superior com: %d\n", somaSup);
    } else {
        printf("Soma maior foi a inferior com: %d\n", somaInf);
    }
}

void print_matriz(int **mat, int linha, int coluna){
    printf("MATRIZ:\n");
    for (int i = 0; i < linha; i++){
        for (int j = 0; j < coluna; j++){
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int coluna, linha;
    int **mat;
    srand(time(NULL));

    printf("Digite o tamanho das linhas e colunas: ");
    scanf("%d%d", &linha, &coluna);

    mat = alocar_matriz(linha, coluna);
    preencher_matriz(mat, linha, coluna);
    print_matriz(mat, linha, coluna);
    soma_superior_inferior(mat, linha, coluna);
    liberar_memoria(mat, linha);

    return 0;
}