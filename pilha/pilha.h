#ifndef PILHA_H
#define PILHA_H

#include "../musicas.h"

typedef struct NoPilha
{
  Musica musica;
  struct NoPilha *proximo;
} NoPilha;

// A Pilha fica separada dos nos e guarda so o campo de controle.
typedef struct
{
  NoPilha *topo;
} Pilha;

void inicializarPilha(Pilha *pilha);
int verificarPilhaVazia(Pilha *pilha);
int empilhar(Pilha *pilha, Musica musica);
int desempilhar(Pilha *pilha, Musica *musica);
void exibirTopoPilha(Pilha *pilha);
int contarPilha(Pilha *pilha);
void esvaziarPilha(Pilha *pilha);
void exibirEstadoPilha(Pilha *pilha);

#endif
