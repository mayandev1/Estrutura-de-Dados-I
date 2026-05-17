#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

struct no {
    char nome[100];
    int matricula;
    float nota;
    No* prox;
};

struct fila {
    No *inicio;
    No *fim;
};

Fila* criar_fila(void){
    Fila* f = (Fila*) malloc(sizeof(Fila));
    f->inicio = f->fim = NULL;
    return f;
}

void inserir_fila(Fila *f){
    No* novo = (No*) malloc(sizeof(No));
    if (novo == NULL) return;

    printf("Digite o nome:\n");
    fgets(novo->nome, 100, stdin);
    novo->nome[strcspn(novo->nome, "\n")] = '\0';

    printf("Digite o numero da matricula:\n");
    scanf("%d", &novo->matricula);
    
    printf("Digite a nota:\n");
    scanf("%f", &novo->nota);

    while (getchar() != '\n');

    printf("Aluno cadastrado!\n");

    novo->prox = NULL;

    if (f->inicio == NULL){
        f->inicio = novo;
        f->fim = novo;
    } else {
        f->fim->prox = novo;
        f->fim = novo;
    }
}

void remover_fila(Fila *f){
    if (f->inicio == NULL){
        printf("Nenhum aluno cadastrado!\n");
        return;
    }

    No *aux = f->inicio;

    f->inicio = f->inicio->prox;

    if (f->inicio == NULL){
        f->fim = NULL;
    }

    free(aux);
}

void liberar_fila(Fila *f){
    if (f == NULL){
        return;
    }

    No *aux = f->inicio;

    while (aux != NULL){
        No *aux2 = aux->prox;
        free(aux);
        aux = aux2;
    }

    free(f);

    printf("Fila apagada!\n");
}

void mostrar_inicio(Fila *f){
    if (f == NULL || f->inicio == NULL){
        printf("Fila vazia.\n");
        return;
    }
    
    printf("Primeiro aluno da fila: %s\n", f->inicio->nome);
    printf("Matricula: %d\n", f->inicio->matricula);
    printf("Nota: %.2f\n", f->inicio->nota);
}

void mostrar_final(Fila *f){
    if (f == NULL || f->fim == NULL){
        printf("Fila vazia.\n");
        return;
    }
    
    printf("Ultimo aluno da fila: %s\n", f->fim->nome);
    printf("Matricula: %d\n", f->fim->matricula);
    printf("Nota: %.2f\n", f->fim->nota);
}

void mostrar_fila(Fila *f){
    if (f == NULL || f->fim == NULL){
        printf("Fila vazia.\n");
        return;
    }
    
    No *aux = f->inicio;
    
    printf("\n=== FILA DE ALUNOS ===\n");
    
    while (aux != NULL){
        
        printf("Nome: %s\n", aux->nome);
        printf("Matricula: %d\n", aux->matricula);
        printf("Nota: %.2f\n", aux->nota);
        printf("----------------------\n");
        
        aux = aux->prox;
    }
}

int tamanho_fila(Fila *f){
    if (f == NULL || f->fim == NULL){
        return 0;
    }
    
    int counter = 0;
    No *aux = f->inicio;

    while (aux != NULL){
        counter++;
        aux = aux->prox;
    }
    
    return counter;
}