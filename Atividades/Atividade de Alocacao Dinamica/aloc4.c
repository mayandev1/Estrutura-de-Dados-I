#include <stdio.h>
#include <stdlib.h>

int ehMaior(int n1, int n2){
    int maior;
    
    if (n1 > n2){
        maior = n1;
    } else {
        maior = n2;
    }
    
    return maior;
}

int main(){
    int n1, n2;

    printf("Digite os dois numeros: ");
    scanf("%d %d", &n1, &n2);

    int *ptr = (int *) malloc(2 * sizeof(int));

    *ptr = ehMaior(n1, n2);

    printf("Maior numero: %d", *ptr);
    return 0;
}