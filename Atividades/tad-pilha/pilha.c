#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

struct no {
    char nome[100];
    int matricula;
    No *prox;
};

struct pilha {
    No *topo;
};

Pilha *criar_pilha(){
    Pilha *p = malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

void push(Pilha* p){
    No *novo = malloc(sizeof(No));

    if (novo == NULL) return;
    
    printf("Digite o nome do aluno:\n");
    scanf(" %[^\n]", novo->nome);

    printf("Digite o numero da matricula:\n");
    scanf("%d", &novo->matricula);
    
    novo->prox = p->topo;
    p->topo = novo;

    printf("Aluno cadastrado com sucesso!!\n");
}

void pop(Pilha* p){

    if (pilha_vazia(p)){
        printf("Nao existem alunos cadastrados para remover.\n");
        return;
    }

    printf("Aluno: %s | Removido com sucesso!\n", p->topo->nome);

    No *temp = p->topo;
    p->topo = temp->prox;
    free(temp);
}

int pilha_vazia(Pilha* p){
    if (p->topo == NULL || p == NULL){
        printf("Pilha vazia.\n");
        return 1;
    }

    return 0;
}

int topo(Pilha* p){
    if (pilha_vazia(p)){
        printf("Nao existe topo.\n");
        return 1;
    }

    return p->topo->matricula;
}

void liberar_pilha(Pilha* p){

    if (pilha_vazia(p)){
        printf("Pilha vazia.\n");
        return;
    }

    while (!pilha_vazia(p)){
        pop(p);
    }
    
    printf("Pilha deletada com sucesso!\n");

    free(p);
}

void mostrar_pilha(Pilha* p){

    if (pilha_vazia(p)){
        return;
    }
    
    No *atual = p->topo;
    printf("Alunos cadastrados no formato de pilha.\n");
    printf("\n");
    printf("---------- PILHA ----------\n");
    printf("TOPO\n");
    printf(" | \n");

    while (atual != NULL){
        printf("[Aluno: %s | <MATRICULA> <%d>\n", atual->nome, atual->matricula);
        atual = atual->prox;
    }
}