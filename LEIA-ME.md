# Spotify — Pilha e Fila em C

Trabalho avaliativo de Estrutura de Dados — Prof. Reinaldo Cotrim

## Integrantes

- Felipe — fila (próximas músicas)
- NOME DO INTEGRANTE A — pilha (histórico)
- NOME DO INTEGRANTE C — menu e programa principal

## Descrição

Simulação de um player de música no terminal. O usuário escolhe músicas de um catálogo e monta a fila do que vai tocar. Cada música que toca vai para um histórico, e é possível voltar para as músicas já tocadas.

Cada nó guarda uma música: ID, título e artista.

### Uso da fila (próximas músicas)

As músicas tocam na mesma ordem em que foram adicionadas: a primeira a entrar na fila é a primeira a tocar (FIFO). A inserção acontece no `fim` e a remoção no `inicio`.

### Uso da pilha (histórico)

Ao voltar, o player retorna para a música tocada por último: a última a entrar no histórico é a primeira a sair (LIFO). A inserção e a remoção acontecem no `topo`.

### Como as duas estruturas se ligam

A opção **3. Proxima** tira a música do início da fila e a coloca no topo do histórico. A opção **4. Voltar** tira a música do topo do histórico e toca ela de novo.

## Arquivos

```
main.c            menu e programa principal
musicas.c/.h      tipo Musica, catálogo e leitura de números validada
fila/fila.c/.h    fila encadeada (inicio e fim)
pilha/pilha.c/.h  pilha encadeada (topo)
```

## Compilação

```
gcc -std=c99 -Wall -Wextra main.c musicas.c fila/fila.c pilha/pilha.c -o spotify
```

## Execução

Linux:

```
./spotify
```

Windows:

```
spotify.exe
```

## Menu

```
1. Ver catalogo
2. Adicionar na fila
3. Proxima
4. Voltar
5. Ver proxima musica
6. Limpar fila
7. Ver ultima musica tocada
8. Ver estado das estruturas
0. Sair
```

A opção 8 mostra os campos de controle (`inicio`, `fim` e `topo`) e a ligação `proximo` de cada nó.

## Exemplo de uso

Adicionando as músicas 3, 7 e 1 na fila (opção 2 três vezes) e vendo o estado (opção 8):

```
===== ESTADO DA FILA =====
Inicio: 0x... (Tempo Perdido)
Fim: 0x... (Evidencias)
[0x...] Tempo Perdido -> proximo: 0x...
[0x...] Bohemian Rhapsody -> proximo: 0x...
[0x...] Evidencias -> proximo: NULL

===== ESTADO DA PILHA =====
Topo: NULL
```

Tocando a próxima (opção 3):

```
Tocando agora: ID: 3 | Tempo Perdido - Legiao Urbana
Musica adicionada ao historico com sucesso.
```

Voltando (opção 4):

```
Tocando novamente: ID: 3 | Tempo Perdido - Legiao Urbana
```

Saindo com músicas pendentes (opção 0):

```
Liberando memoria...
Musicas pendentes na fila: 2
Musicas no historico: 0
Programa encerrado.
```

## Roteiro dos testes

| Teste | Fila | Pilha |
|---|---|---|
| 1. Consulta e remoção com a estrutura vazia | 5 e 3 | 7 e 4 |
| 2. Inserir três e conferir a ordem de saída | 2 três vezes, depois 3 três vezes | 3 três vezes, depois 4 três vezes |
| 3. Consultar sem alterar | 5 duas vezes e 8 | 7 duas vezes e 8 |
| 4. Remover o único elemento | 3 até sobrar um, 3 de novo e 8 (`inicio` e `fim` NULL) | 4 até sobrar um, 4 de novo e 8 (`topo` NULL) |
| 5. Inserir depois de esvaziar | 2 e 8 | 3 e 8 |
| 6. Sair com elementos pendentes | 0 | 0 |
