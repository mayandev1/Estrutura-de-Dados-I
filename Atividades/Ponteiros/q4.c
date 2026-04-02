#include <stdio.h>
#include <stdlib.h>

void preencher_vetor(int vet[], int n){
    printf("Digite os elementos do vetor: ");
    for (int i = 0; i < n; i++){
        printf("\nPosicao [%d]: ", i);
        scanf("%d", &vet[i]);
    }
}

void mostrar_vetor(int vet[], int n){
    printf("Valores contidos no vetor: ");
    for (int i = 0; i < n; i++){
        printf("%d ", vet[i]);
    }
}

void separar_pares(int vet[], int n, int pares[], int *qtd_pares){
    *qtd_pares = 0;
    
    for (int i = 0; i < n; i++){
        if (vet[i] % 2 == 0){
            (*qtd_pares)++;
        }
    }
}

void separar_impares(int vet[], int n, int impares[], int *qtd_impares){
    *qtd_impares = 0;

    for (int i = 0; i < n; i++){
        if (vet[i] % 2 == 0){
            (*qtd_impares)++;
        }
    }
}

int main(){

    const int TAM = 10;
    int vetor[TAM], qntPares = 0, qntImpares = 0, pares[TAM], impares[TAM];

    preencher_vetor(vetor, TAM);
    mostrar_vetor(vetor, TAM);
    separar_pares(vetor, TAM, pares, &qntPares);
    separar_impares(vetor, TAM, impares, &qntImpares);
    
    printf("\nVetor de Pares:\n");
    for (int i = 0; i < TAM; i++){
        printf("%d ", pares[i]);
    }
    printf("\n");
    
    printf("\nVetor de Impares:\n");
    for (int i = 0; i < TAM; i++){
        printf("%d ", impares[i]);
    }
    printf("\n");

    return 0;
}