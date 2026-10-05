#ifndef MUSICAS_H
#define MUSICAS_H

typedef struct
{
  int id;
  char titulo[51];
  char artista[51];
} Musica;

void limparBuffer(void);
int lerInteiro(void);
Musica criarMusica(int id, char titulo[], char artista[]);
void exibirMusica(const Musica *musica);
int carregarCatalogo(Musica catalogo[]);
void exibirCatalogo(Musica catalogo[], int quantidade);
int buscarMusicaPorId(Musica catalogo[], int quantidade, int id, Musica *musica);

#endif
