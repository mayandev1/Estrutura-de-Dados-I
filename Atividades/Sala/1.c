#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ehPrimo(int n) {
    int i;
    
    if (n <= 1) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;
    
    for (i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return 0;
    }
    
    return 1;
}

int main(){
    int TAM;
    srand(time(NULL));

    printf("Informe o tamanho das duas matrizes: ");
    scanf("%d", &TAM);

    int **mat1, **mat2;

    // Alocando matrizes

    mat1 = (int**) malloc(sizeof(int*) * TAM);
    mat2 = (int**) malloc(sizeof(int*) * TAM);

    if (mat1 == NULL){
        exit(1);
    }

    if (mat2 == NULL){
        exit(1);
    }
    
    for (int i = 0; i < TAM; i++){
        mat1[i] = (int*) calloc(TAM, sizeof(int));
        if (mat1[i] == NULL){
            exit(1);
        }
    }
    
    for (int i = 0; i < TAM; i++){
        mat2[i]= (int*) calloc(TAM, sizeof(int));
        if (mat2[i] == NULL){
            exit(1);
        }
    }

    // Preencher as matrizes

    for (int i = 0; i < TAM; i++){
        for (int j = 0; j < TAM; j++){
            mat1[i][j] = rand() % 100;
        }
    }
    
    for (int i = 0; i < TAM; i++){
        for (int j = 0; j < TAM; j++){
            mat2[i][j] = rand() % 100;
        }
    }
    
    printf("Matriz 1:\n");
    for (int i = 0; i < TAM; i++){
        for (int j = 0; j < TAM; j++){
            printf("%d\t", mat1[i][j]);
        }
        printf("\n");
    }
    
    printf("\nMatriz 2:\n");
    for (int i = 0; i < TAM; i++){
        for (int j = 0; j < TAM; j++){
            printf("%d\t", mat2[i][j]);
        }
        printf("\n");
    }
    
    int produto[TAM][TAM];
    for (int i = 0; i < TAM; i++){
        for (int j = 0; j < TAM; j++){
            produto[i][j] = mat1[i][j] * mat2[i][j];
        }
    }
    
    printf("\nProduto das duas matrizes:\n");
    for (int i = 0; i < TAM; i++){
        for (int j = 0; j < TAM; j++){
            printf("%d\t", produto[i][j]);
        }
        printf("\n");
    }
    
    int countPar = 0, countImpar = 0, countPrimo = 0;

    printf("\nNumeros pares do produto:\n");
    for (int i = 0; i < TAM; i++){
        for (int j = 0; j < TAM; j++){
            if (produto[i][j] % 2 == 0){
                countPar++;
                printf("%d ", produto[i][j]);
            }
        }
    }

    printf("\nNumeros impares do produto:\n");
    for (int i = 0; i < TAM; i++){
        for (int j = 0; j < TAM; j++){
            if (produto[i][j] % 2 == 1){
                countImpar++;
                printf("%d ", produto[i][j]);
            }   
        }
    }

    printf("\nNumeros primos do produto:\n");
    for (int i = 0; i < TAM; i++){
        for (int j = 0; j < TAM; j++){
            if (ehPrimo(produto[i][j])){
                printf("%d ", produto[i][j]);
                countPrimo++;
            }
        }
    }

    printf("\nQuantidade de numeros pares eh igual a %d!\n", countPar);
    printf("Quantidade de numeros impares igual a %d!\n", countImpar);
    printf("Quantidade de numeros primos eh igual a %d!\n", countPrimo);

    
    for (int i = 0; i < TAM; i++){
        free(mat1[i]);
        free(mat2[i]);
    }
    free(mat1);
    free(mat2);
    
    return 0;
}