#include <stdio.h>
#include <stdlib.h>

int* concatenar(int vet1[], int tam1, int vet2[], int tam2, int *novoTam){
    *novoTam = tam1 + tam2;
    int *novo = (int*) malloc(*novoTam * sizeof(int));
    
    if (novo == NULL){
        printf("Erro na aloc!");
        exit(1);
    }

    for (int i = 0; i < tam1; i++){
        novo[i] = vet1[i];
    }

    for (int i = 0; i < tam2; i++){
        novo[tam1 + i] = vet2[i];
    }
    
    return novo;
}

int main(){
    int N1, N2, novoTAM;

    printf("Digite o tamanho de cada vetor: ");
    scanf("%d %d", &N1, &N2);

    int vetorA[N1], vetorB[N2];

    printf("\nPreencha o vetorA: ");
    for (int i = 0; i < N1; i++){
        scanf("%d", &vetorA[i]);
    }
    
    printf("\nPreencha o vetorB: ");
    for (int i = 0; i < N2; i++){
        scanf("%d", &vetorB[i]);
    }

    int *concatenado = concatenar(vetorA, N1, vetorB, N2, &novoTAM);

    printf("Vetor A: ");
    for (int i = 0; i < N1; i++){
        printf("%d ", vetorA[i]);
    }
    printf("\n");
    
    printf("Vetor B: ");
    for (int i = 0; i < N2; i++){
        printf("%d ", vetorB[i]);
    }
    printf("\n");

    printf("Concatenado: ");
    for (int i = 0; i < novoTAM; i++){
        printf("%d ", concatenado[i]);
    }
    printf("\n");

    free(concatenado);

    return 0;
}