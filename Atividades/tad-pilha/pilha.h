#ifndef PILHA_H
#define PILHA_H

typedef struct no No;
typedef struct pilha Pilha;

Pilha *criar_pilha();
void push(Pilha* p);
void pop(Pilha* p);
int topo(Pilha* p);
int pilha_vazia(Pilha* p);
void liberar_pilha(Pilha* p);
void mostrar_pilha(Pilha* p);

#endif // PILHA_H