#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

void inicializarPilha(Pilha *pilha)
{
  pilha->topo = NULL;
}

int verificarPilhaVazia(Pilha *pilha)
{
  if (pilha->topo == NULL)
  {
    return 1;
  }

  return 0;
}

int empilhar(Pilha *pilha, Musica musica)
{
  NoPilha *novo = malloc(sizeof(NoPilha));

  if (novo == NULL)
  {
    printf("Falha na alocacao de memoria.\n");
    return 1;
  }

  novo->musica = musica;
  novo->proximo = pilha->topo;
  pilha->topo = novo;

  printf("Musica adicionada ao historico com sucesso.\n");
  return 0;
}

int desempilhar(Pilha *pilha, Musica *musica)
{
  NoPilha *auxiliar;

  if (verificarPilhaVazia(pilha) == 1)
  {
    printf("A pilha esta vazia.\n");
    return 1;
  }

  auxiliar = pilha->topo;
  *musica = auxiliar->musica;

  // O topo passa para o proximo no. Se era o unico, vira NULL.
  pilha->topo = auxiliar->proximo;

  free(auxiliar);
  return 0;
}

void exibirTopoPilha(Pilha *pilha)
{
  if (verificarPilhaVazia(pilha) == 1)
  {
    printf("A pilha esta vazia.\n");
    return;
  }

  printf("Ultima musica tocada: ");
  exibirMusica(&pilha->topo->musica);
}

int contarPilha(Pilha *pilha)
{
  NoPilha *auxiliar = pilha->topo;
  int quantidade = 0;

  while (auxiliar != NULL)
  {
    quantidade++;
    auxiliar = auxiliar->proximo;
  }

  return quantidade;
}

void esvaziarPilha(Pilha *pilha)
{
  NoPilha *auxiliar;

  while (pilha->topo != NULL)
  {
    auxiliar = pilha->topo;
    pilha->topo = pilha->topo->proximo;
    free(auxiliar);
  }
}

void exibirEstadoPilha(Pilha *pilha)
{
  NoPilha *auxiliar = pilha->topo;

  printf("\n===== ESTADO DA PILHA =====\n");

  if (pilha->topo == NULL)
  {
    printf("Topo: NULL\n");
  }
  else
  {
    printf("Topo: %p (%s)\n", (void *)pilha->topo, pilha->topo->musica.titulo);
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
