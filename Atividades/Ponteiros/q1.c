#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool is_primo(int x){
    if (x <= 1){
        return false;
    }
    
    for (int i = 2; i * i <= x; i++){
        if (x % i == 0){
            return false;
        }
    }
    
    return true;
}

int verificar_quantidade_primos(int vet[], int n){
    int countPrimos = 0;

    for (int i = 0; i < n; i++){
        if (is_primo(vet[i])){
            countPrimos++;
        }
    }
    
    return countPrimos;
}

int main(){

    const int TAM = 10;
    int vetor[TAM], Primos = 0; 

    preencher_vetor(vetor, TAM);
    mostrar_vetor(vetor, TAM);
    Primos = verificar_quantidade_primos(vetor, TAM);

    printf("\nNumero de primos encontrados: %d", Primos);
    return 0;
}
