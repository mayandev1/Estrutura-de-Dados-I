#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int *mat[5];

    srand(time(NULL));

    for(int i = 0; i < 5; i++){
        mat[i] = (int*) malloc(5 * sizeof(int));
    }

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            mat[i][j] = rand() % 100;
        }
    }

    printf("Matriz:\n");
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < 5; i++){
        free(mat[i]);
    }

    return 0;
}