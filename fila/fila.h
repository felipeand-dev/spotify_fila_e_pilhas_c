#ifndef FILA_H
#define FILA_H

#include "../musicas.h"

typedef struct NoFila
{
  Musica musica;
  struct NoFila *proximo;
} NoFila;

// A Fila fica separada dos nos e guarda so os campos de controle.
typedef struct
{
  NoFila *inicio;
  NoFila *fim;
} Fila;

void inicializarFila(Fila *fila);
int verificarFilaVazia(Fila *fila);
int enfileirar(Fila *fila, Musica musica);
int desenfileirar(Fila *fila, Musica *musica);
void exibirInicioFila(Fila *fila);
int contarFila(Fila *fila);
void esvaziarFila(Fila *fila);
void exibirEstadoFila(Fila *fila);

#endif
