# Player de Musica em C

Aplicacao de linha de comando que simula um player de musica, inspirada na fila de reproducao e no historico do Spotify. O projeto mostra, na pratica, quando usar uma fila e quando usar uma pilha, e como as duas estruturas trabalham juntas no mesmo programa.

Projeto desenvolvido para a disciplina de Estrutura de Dados, com foco em alocacao dinamica, ponteiros, modularizacao e analise de complexidade.

## Visao geral

O player organiza as musicas em duas estruturas encadeadas:

| Area | Estrutura | Regra | Uso no sistema |
| --- | --- | --- | --- |
| Proximas musicas | Fila encadeada | FIFO | As musicas tocam na mesma ordem em que foram adicionadas |
| Historico | Pilha encadeada | LIFO | Ao voltar, o player retorna para a ultima musica tocada |

As duas estruturas se ligam na reproducao:

```text
Catalogo --(2. Adicionar)--> Fila --(3. Proxima)--> Pilha --(4. Voltar)--> toca de novo
                             fim -> ... -> inicio    topo
```

Cada musica possui ID, titulo e artista.

## Funcionalidades

- Exibicao do catalogo de musicas
- Insercao de musicas no fim da fila
- Reproducao da proxima musica, que sai do inicio da fila e entra no topo do historico
- Retorno para a ultima musica tocada, que sai do topo do historico
- Consulta da proxima musica e da ultima tocada sem alterar as estruturas
- Esvaziamento da fila com liberacao da memoria
- Exibicao do estado das estruturas: campos `inicio`, `fim` e `topo`, endereco de cada no e sua ligacao `proximo`
- Mensagens para fila vazia, historico vazio, musica inexistente, entrada invalida e falha de alocacao
- Liberacao de todos os nos pendentes ao encerrar

## Organizacao do projeto

```text
.
|-- main.c              # Menu principal e ligacao entre fila e pilha
|-- musicas.h           # Estrutura Musica, catalogo e leitura validada
|-- musicas.c
|-- fila/
|   |-- fila.h          # Interface da fila encadeada
|   `-- fila.c
|-- pilha/
|   |-- pilha.h         # Interface da pilha encadeada
|   `-- pilha.c
`-- README.md
```

## Modelo de dados

```c
typedef struct
{
  int id;
  char titulo[51];
  char artista[51];
} Musica;
```

Os nos guardam a musica por valor e ficam separados das estruturas de controle:

```c
typedef struct NoFila
{
  Musica musica;
  struct NoFila *proximo;
} NoFila;

typedef struct
{
  NoFila *inicio;
  NoFila *fim;
} Fila;

typedef struct NoPilha
{
  Musica musica;
  struct NoPilha *proximo;
} NoPilha;

typedef struct
{
  NoPilha *topo;
} Pilha;
```

## Como compilar

### Requisito

- GCC com suporte ao padrao C99

### Build

```bash
gcc -std=c99 -Wall -Wextra main.c musicas.c fila/fila.c pilha/pilha.c -o player
```

O projeto compila sem nenhum warning com `-Wall -Wextra`.

### Executar

```bash
./player
```

No Windows, execute `player.exe`.

### Verificar a memoria

```bash
gcc -std=c99 -Wall -Wextra -g -fsanitize=address,undefined main.c musicas.c fila/fila.c pilha/pilha.c -o player
./player
```

Com o AddressSanitizer, qualquer vazamento ou acesso invalido aparece ao encerrar o programa.

## Exemplo de uso

Depois de adicionar tres musicas na fila e tocar a primeira, a opcao `8. Ver estado das estruturas` mostra:

```text
===== ESTADO DA FILA =====
Inicio: 0x5581a3c0 (Bohemian Rhapsody)
Fim: 0x5581a400 (Evidencias)
[0x5581a3c0] Bohemian Rhapsody -> proximo: 0x5581a400
[0x5581a400] Evidencias -> proximo: NULL

===== ESTADO DA PILHA =====
Topo: 0x5581a440 (Tempo Perdido)
[0x5581a440] Tempo Perdido -> proximo: NULL
```

## Analise de complexidade

Na notacao Big-O, `n` representa a quantidade de musicas armazenadas na estrutura.

| Operacao | Fila | Pilha |
| --- | ---: | ---: |
| Inicializar | `O(1)` | `O(1)` |
| Verificar se esta vazia | `O(1)` | `O(1)` |
| Inserir | `O(1)` | `O(1)` |
| Remover | `O(1)` | `O(1)` |
| Consultar sem remover | `O(1)` | `O(1)` |
| Contar | `O(n)` | `O(n)` |
| Esvaziar | `O(n)` | `O(n)` |
| Exibir estado | `O(n)` | `O(n)` |

A busca de uma musica no catalogo e `O(k)`, sendo `k` o tamanho do catalogo.

As duas estruturas utilizam memoria `O(n)`, pois existe um no alocado dinamicamente para cada musica.

## Decisoes de implementacao

- A fila guarda um ponteiro para o `fim`, entao a insercao acontece em `O(1)`, sem percorrer a estrutura.
- Quando a fila perde o unico elemento, `inicio` e `fim` voltam a ser `NULL`. Na pilha, o `topo` passa para o proximo no e fica `NULL` quando ela esvazia.
- A remocao devolve a musica por ponteiro, o que permite tirar a musica da fila e coloca-la no historico sem acoplar os dois modulos.
- Ao voltar, a musica sai do historico e toca de novo, mas nao volta para a fila. Inserir no inicio da fila quebraria a regra FIFO.
- As operacoes que podem falhar retornam `0` em caso de sucesso e `1` em caso de falha, e cada funcao exibe a propria mensagem de erro.
- A entrada numerica e validada, entao digitar letras no lugar de numeros nao trava o programa.
- A memoria e liberada ao esvaziar a fila e tambem antes do encerramento do programa.

## Licenca

Projeto academico desenvolvido para fins educacionais.
# spotify_fila_e_pilhas_c
