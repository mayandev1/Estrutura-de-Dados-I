#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    int Nlinhas, Mcolunas, **matriz, num;

    printf("Digite a quantidade de linhas e colunas:\n");
    scanf("%d%d", &Nlinhas, &Mcolunas);
    
    matriz = (int**) malloc(sizeof(int*) * Nlinhas);
    if (matriz == NULL){
        printf("Erro de alocacao");
        exit(1);
    }

    for (int i = 0; i < Nlinhas; i++){
        matriz[i] = (int*) calloc(Mcolunas, sizeof(int));
        if (matriz[i] == NULL){
            printf("Erro de alocacao");
            exit(1);
        } 
    }
    
    for (int i = 0; i < Nlinhas; i++){
        for (int j = 0; j < Mcolunas; j++){
            matriz[i][j] = rand() % 200;
        }
    }
    
    printf("Digite um valor para buscar na matriz:\n");
    scanf("%d", &num);
    
    printf("Matriz:\n");
    for (int i = 0; i < Nlinhas; i++){
        for (int j = 0; j < Mcolunas; j++){
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
    
    for (int i = 0; i < Nlinhas; i++){
        for (int j = 0; j < Mcolunas; j++){
            if (matriz[i][j] == num){
                printf("Linha %d || Coluna %d\n", i, j);
            }
        }
    }
    
    for (int i = 0; i < Nlinhas; i++){
        free(matriz[i]);
    }
    free(matriz);
    
}