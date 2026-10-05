#include <stdio.h>
#include <string.h>
#include "musicas.h"

void limparBuffer(void)
{
  int caractere;

  while ((caractere = getchar()) != '\n' && caractere != EOF)
  {
  }
}

int lerInteiro(void)
{
  int valor = 0;

  while (scanf("%d", &valor) != 1)
  {
    limparBuffer();
    printf("Valor invalido. Digite novamente: ");
  }

  return valor;
}

Musica criarMusica(int id, char titulo[], char artista[])
{
  Musica musica;

  musica.id = id;
  strcpy(musica.titulo, titulo);
  strcpy(musica.artista, artista);

  return musica;
}

void exibirMusica(const Musica *musica)
{
  printf("ID: %d | %s - %s\n", musica->id, musica->titulo, musica->artista);
}

int carregarCatalogo(Musica catalogo[])
{
  catalogo[0] = criarMusica(1, "Evidencias", "Chitaozinho e Xororo");
  catalogo[1] = criarMusica(2, "Asa Branca", "Luiz Gonzaga");
  catalogo[2] = criarMusica(3, "Tempo Perdido", "Legiao Urbana");
  catalogo[3] = criarMusica(4, "Garota de Ipanema", "Tom Jobim");
  catalogo[4] = criarMusica(5, "Aquarela", "Toquinho");
  catalogo[5] = criarMusica(6, "Pais e Filhos", "Legiao Urbana");
  catalogo[6] = criarMusica(7, "Bohemian Rhapsody", "Queen");
  catalogo[7] = criarMusica(8, "Billie Jean", "Michael Jackson");
  catalogo[8] = criarMusica(9, "Blinding Lights", "The Weeknd");
  catalogo[9] = criarMusica(10, "Shape of You", "Ed Sheeran");

  return 10;
}

void exibirCatalogo(Musica catalogo[], int quantidade)
{
  printf("\n===== CATALOGO =====\n");

  for (int i = 0; i < quantidade; i++)
  {
    exibirMusica(&catalogo[i]);
  }
}

int buscarMusicaPorId(Musica catalogo[], int quantidade, int id, Musica *musica)
{
  for (int i = 0; i < quantidade; i++)
  {
    if (catalogo[i].id == id)
    {
      *musica = catalogo[i];
      return 0;
    }
  }

  return 1;
}
