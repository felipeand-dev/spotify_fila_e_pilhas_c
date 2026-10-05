#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void inicializarFila(Fila *fila)
{
  fila->inicio = NULL;
  fila->fim = NULL;
}

int verificarFilaVazia(Fila *fila)
{
  if (fila->inicio == NULL)
  {
    return 1;
  }

  return 0;
}

int enfileirar(Fila *fila, Musica musica)
{
  NoFila *novo = malloc(sizeof(NoFila));

  if (novo == NULL)
  {
    printf("Falha na alocacao de memoria.\n");
    return 1;
  }

  novo->musica = musica;
  novo->proximo = NULL;

  // Insercao sempre no fim. Com a fila vazia, o novo no tambem vira o inicio.
  if (verificarFilaVazia(fila) == 1)
  {
    fila->inicio = novo;
  }
  else
  {
    fila->fim->proximo = novo;
  }

  fila->fim = novo;

  printf("Musica adicionada a fila com sucesso.\n");
  return 0;
}

int desenfileirar(Fila *fila, Musica *musica)
{
  NoFila *auxiliar;

  if (verificarFilaVazia(fila) == 1)
  {
    printf("A fila esta vazia.\n");
    return 1;
  }

  auxiliar = fila->inicio;
  *musica = auxiliar->musica;
  fila->inicio = auxiliar->proximo;

  // Se saiu o unico elemento, o fim tambem volta para NULL.
  if (fila->inicio == NULL)
  {
    fila->fim = NULL;
  }

  free(auxiliar);
  return 0;
}

void exibirInicioFila(Fila *fila)
{
  if (verificarFilaVazia(fila) == 1)
  {
    printf("A fila esta vazia.\n");
    return;
  }

  printf("Proxima musica: ");
  exibirMusica(&fila->inicio->musica);
}

int contarFila(Fila *fila)
{
  NoFila *auxiliar = fila->inicio;
  int quantidade = 0;

  while (auxiliar != NULL)
  {
    quantidade++;
    auxiliar = auxiliar->proximo;
  }

  return quantidade;
}

void esvaziarFila(Fila *fila)
{
  NoFila *auxiliar;

  while (fila->inicio != NULL)
  {
    auxiliar = fila->inicio;
    fila->inicio = fila->inicio->proximo;
    free(auxiliar);
  }

  fila->fim = NULL;
}

void exibirEstadoFila(Fila *fila)
{
  NoFila *auxiliar = fila->inicio;

  printf("\n===== ESTADO DA FILA =====\n");

  if (fila->inicio == NULL)
  {
    printf("Inicio: NULL\n");
  }
  else
  {
    printf("Inicio: %p (%s)\n", (void *)fila->inicio, fila->inicio->musica.titulo);
  }

  if (fila->fim == NULL)
  {
    printf("Fim: NULL\n");
  }
  else
  {
    printf("Fim: %p (%s)\n", (void *)fila->fim, fila->fim->musica.titulo);
  }

  while (auxiliar != NULL)
  {
    if (auxiliar->proximo == NULL)
    {
      printf("[%p] %s -> proximo: NULL\n", (void *)auxiliar,
             auxiliar->musica.titulo);
    }
    else
    {
      printf("[%p] %s -> proximo: %p\n", (void *)auxiliar,
             auxiliar->musica.titulo, (void *)auxiliar->proximo);
    }

    auxiliar = auxiliar->proximo;
  }
}
