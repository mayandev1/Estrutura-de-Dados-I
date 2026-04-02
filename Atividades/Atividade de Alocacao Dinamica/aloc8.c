#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int N;

    printf("Qual o tamanho do vetor de char?\n");
    scanf("%d", &N);
    getchar();

    char *vetor = (char*) malloc((N + 1) * sizeof(char));

    if (vetor == NULL){
        printf("Erro de alocacao!\n");
        exit(1);
    }
    
    printf("Digite sua palavra ou frase: ");
    fgets(vetor, N + 1, stdin);

    vetor[strcspn(vetor, "\n")] = '\0';
    int tamanho = strlen(vetor);

    printf("\nOriginal: %s\n", vetor);

    printf("Vetor preenchido invertido: ");
    for (int i = 0; i < tamanho; i++){
        printf("%c", vetor[tamanho - 1 - i]);
    }
    printf("\n");

    free(vetor);
    return 0;
}