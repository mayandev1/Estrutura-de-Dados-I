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

int soma_posicoes_pares(int vet[], int n){
    int soma = 0;

    for (int i = 0; i < n; i++){
        if (vet[i] % 2 == 0){
            soma += vet[i];
        }
    }
    
    return soma;
}

int soma_posicoes_impares(int vet[], int n){
    int soma = 0;

    for (int i = 0; i < n; i++){
        if (vet[i] % 2 != 0){
            soma += vet[i];
        }
    }
    
    return soma;
}

int main(){

    const int TAM = 10;
    int vetor[TAM], somaPares = 0, somaImpares = 0; 

    preencher_vetor(vetor, TAM);
    mostrar_vetor(vetor, TAM);
    somaPares = soma_posicoes_pares(vetor, TAM);
    somaImpares = soma_posicoes_impares(vetor, TAM);

    printf("\nNumero da soma dos numeros pares encontrados: %d", somaPares);
    printf("\nNumero da soma dos numeros impares encontrados: %d", somaImpares);
    return 0;
}
