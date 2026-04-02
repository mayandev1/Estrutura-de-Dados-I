#include <stdio.h>
#include <stdlib.h>

int *encontrarElemento(int v1[], int n1, int p1, int p2, int *tam){
    if (p1 < 0 || p2 >= n1 || p1 > p2){
        return NULL;
    }

    *tam = p2 - p1 + 1;

    int *novoVet = (int*) malloc(*tam * sizeof(int));
    if (novoVet == NULL){
        printf("Erro na aloc!");
        exit(1);
    }
    
    for (int i = 0; i < *tam; i++){
        novoVet[i] = v1[p1 + i];
    }
    
    return novoVet;
}

int main(){
    int N, tamanho;
    
    printf("Digite o tamanho do vetor:\n");
    scanf("%d", &N);

    int vet[N];
    
    printf("Preencha o vetor:\n");
    for (int i = 0; i < N; i++){
        scanf("%d", &vet[i]);
    }

    int posicao1, posicao2;
    printf("Digite as duas posicoes:\n");
    scanf("%d %d", &posicao1, &posicao2);

    int *elementos = encontrarElemento(vet, N, posicao1, posicao2, &tamanho);

    if (elementos == NULL){
        printf("Posicoes Invalidas\n");
    } else {
        printf("Sub-Vetor: ");
        for (int i = 0; i < tamanho; i++){
            printf("%d ", elementos[i]);
        }
        printf("\n");
        
        free(elementos);
    }
    
    return 0;
}