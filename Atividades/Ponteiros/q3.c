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

int contar_pares(int vet[], int n){
    int countPares = 0;
    for (int i = 0; i < n; i++){
        if (vet[i] % 2 == 0){
            countPares++;
        }
    }
    
    return countPares;
}

float calcular_media(int vet[], int n){
    int soma = 0;

    for (int i = 0; i < n; i++){
        soma += vet[i];
    }

    return soma / (float)n;
}

int main(){

    const int TAM = 10;
    int vetor[TAM], qntPares = 0;
    float media = 0; 

    preencher_vetor(vetor, TAM);
    mostrar_vetor(vetor, TAM);
    qntPares = contar_pares(vetor, TAM);
    media = calcular_media(vetor, TAM);

    printf("Quantidade de numero pares encontrados: %d\n", qntPares);
    printf("\nMedia total: %.2f\n", media);
    return 0;
}