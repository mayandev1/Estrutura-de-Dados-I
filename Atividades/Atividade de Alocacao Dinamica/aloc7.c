#include <stdio.h>
#include <stdlib.h>

int* alocar_memoria(int v[], int tam, int *novo_tam){
    int count = 0;
    int *novo = (int*) malloc(count * sizeof(int));

    for (int i = 0; i < tam; i++){
        int repetido = 0;

        for (int j = 0; j < count; j++){
            if (v[i] == novo[j]){
                repetido = 1;
                break;
            }
        }
        
        if (!repetido){
            novo[count] = v[i];
            count++;
        }
    }

    if (novo == NULL){
        printf("Erro de alocacao!\n");
        exit(1);
    }

    *novo_tam = count;

    return novo;
}

int main(){
    const int TAM = 10;
    int vetor[TAM], novo_TAM;

    printf("Digite os elementos do vetor fixo: ");
    for (int i = 0; i < TAM; i++){
        scanf("%d", &vetor[i]);
    }
    
    int *vetorSemRepeticoes = alocar_memoria(vetor, TAM, &novo_TAM);

    printf("\nVetor principal: ");
    for (int i = 0; i < TAM; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
    
    printf("\nVetor sem repeticoes: ");
    for (int i = 0; i < novo_TAM; i++){
        printf("%d ", vetorSemRepeticoes[i]);
    }
    printf("(tamanho %d)\n", novo_TAM);
    
    free(vetorSemRepeticoes);

    return 0;
}