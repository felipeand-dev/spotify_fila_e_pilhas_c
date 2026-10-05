#include <stdio.h>
#include <stdlib.h>
#include "fila/fila.h"
#include "pilha/pilha.h"

void mostrarEstado(Fila *fila, Pilha *pilha);

int main(void)
{
    int opcao = -1;
    int quantidade_catalogo = 0;
    Musica catalogo[10];
    Fila fila;
    Pilha historico;

    inicializarFila(&fila);
    inicializarPilha(&historico);
    quantidade_catalogo = carregarCatalogo(catalogo);

    do
    {
        printf("\n====================================\n");
        printf("              SPOTIFY \n");
        printf("====================================\n");
        printf("1. Ver catalogo\n");
        printf("2. Adicionar na fila\n");
        printf("3. Proxima\n");
        printf("4. Voltar\n");
        printf("5. Ver proxima musica\n");
        printf("6. Limpar fila\n");
        printf("7. Ver ultima musica tocada\n");
        printf("8. Ver estado das estruturas\n");
        printf("0. Sair\n");
        printf("====================================\n");
        printf("Escolha uma opcao: ");

        if (scanf("%d", &opcao) != 1)
        {
            while (getchar() != '\n')
            {
            }

            printf("\nEntrada invalida. Digite um numero.\n");
            continue;
        }

        switch (opcao)
        {
            case 1:
                exibirCatalogo(catalogo, quantidade_catalogo);
                break;

            case 2:
            {
                int id = 0;
                Musica musica;

                exibirCatalogo(catalogo, quantidade_catalogo);
                printf("Digite o ID da musica: ");
                id = lerInteiro();

                if (buscarMusicaPorId(catalogo, quantidade_catalogo, id, &musica) == 0)
                {
                    enfileirar(&fila, musica);
                }
                else
                {
                    printf("Musica nao encontrada.\n");
                }
            }
            break;

            case 3:
            {
                Musica musica;

                // A musica sai do inicio da fila (FIFO) e vai para o topo do historico (LIFO).
                if (desenfileirar(&fila, &musica) == 0)
                {
                    printf("\nTocando agora: ");
                    exibirMusica(&musica);
                    empilhar(&historico, musica);
                }
            }
            break;

            case 4:
            {
                Musica musica;

                if (desempilhar(&historico, &musica) == 0)
                {
                    printf("\nTocando novamente: ");
                    exibirMusica(&musica);
                }
            }
            break;

            case 5:
                exibirInicioFila(&fila);
                break;

            case 6:
                esvaziarFila(&fila);
                printf("Fila esvaziada com sucesso.\n");
                break;

            case 7:
                exibirTopoPilha(&historico);
                break;

            case 8:
                mostrarEstado(&fila, &historico);
                break;

            case 0:
                printf("\nLiberando memoria...\n");
                printf("Musicas pendentes na fila: %d\n", contarFila(&fila));
                printf("Musicas no historico: %d\n", contarPilha(&historico));
                esvaziarFila(&fila);
                esvaziarPilha(&historico);
                printf("Programa encerrado.\n");
                break;

            default:
                printf("\nOpcao invalida.\n");
        }

    } while (opcao != 0);

    return 0;
}

void mostrarEstado(Fila *fila, Pilha *pilha)
{
    exibirEstadoFila(fila);
    exibirEstadoPilha(pilha);
}
