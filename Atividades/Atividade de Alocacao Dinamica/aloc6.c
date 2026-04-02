#include <stdio.h>
#include <stdlib.h>

int* alocar_memoria(int tamanho){
    int *ptr = (int*) malloc(tamanho * sizeof(int));

    if (ptr == NULL){
        printf("Erro de alocacao!\n");
        exit(1);
    }

    return ptr;
}

int main(){
    int TAM;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &TAM);

    int *vetor = alocar_memoria(TAM);

    printf("Preenchar o vetor:\n");
    for (int i = 0; i < TAM; i++){
        scanf("%d", &vetor[i]);
    }

    printf("Vetor preenchido:\n");
    for (int i = 0; i < TAM; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
    
    free(vetor);

    return 0;
}
