#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "listaDinEncad.h"

void menu()
{
    printf("Lista Dinamica Encadeada                      \n\n");
    printf(" 1  - Cadastrar Matricula                       \n");
    printf(" 2  - Consultar Matricula                       \n");
    printf(" 3  - Consultar Lista                           \n");
    printf(" 4  - Excluir Matricula                         \n");
    printf(" 5  - Cria Lista                                \n");
    printf(" 6  - Preenche Lista (Adiciona 5 Elementos)     \n");
    printf(" 7  - Remove Tudo                               \n");
    printf(" 8  - Tamanho da Lista                          \n");
    printf(" 9  - Imprimi Lista                             \n");
    printf(" 10 - Insere Lista Inicio                       \n");
    printf(" 11 - Remove Lista Inicio                       \n");
    printf(" 12 - Insere Lista Final                        \n");
    printf(" 13 - Remove Lista Final                        \n");
    printf(" 14 - Remove Lista Matricula                    \n");
    printf(" 15 - Consulta lista Posicao                    \n");
    printf(" 16 - Consulta lista Matricula                  \n");
    printf("------------------------------------------------\n");
    printf(" 0 - Sair                                       \n");
    printf("------------------------------------------------\n");
    return;
}

int main()
{
    int matri, opcao;
    bool con = true;
    Lista* li = cria_lista();
    struct aluno dados;

    while(con)
    {
        system("cls");
        menu();
        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);
        switch(opcao)
        {
        case 1:
            printf("Digite a Matricula: ");
            scanf("%d", &dados.matricula);
            printf("Digite o Nome: ");
            fseek(stdin,0,SEEK_END);
            scanf("%s", dados.nome);
            printf("Digite a Nota 01: ");
            scanf("%f", &dados.n1);
            printf("Digite a Nota 02: ");
            scanf("%f", &dados.n2);
            printf("Digite a Nota 03: ");
            scanf("%f", &dados.n3);
            insere_lista_ordenada(li, dados);
            break;
        case 2:
            if(lista_vazia(li)){
                printf("\nLista Vazia...\n");
                system("pause");
                break;
            }
            printf("Qual matricula deseja consultar? ");
            scanf("%d", &matri);
            consulta_lista_mat(li, matri, &dados);
            printf("\nMatricula: %d", dados.matricula);
            printf("\nNome: %s", dados.nome);
            printf("\nNotas: %.2f %.2f %.2f\n",dados.n1, dados.n2, dados.n3);
            system("pause");
            break;
        case 3:
            if(lista_vazia(li)){
                printf("\nLista Vazia...\n");
                opcao = 0;
                system("pause");
                break;
            }
            imprime_lista(li);
            system("pause");
            break;
        case 4:
            if(lista_vazia(li)){
                printf("\nLista Vazia...\n");
                system("pause");
                break;
            }
            printf("Qual matricula deseja remover? ");
            scanf("%d", &matri);
            remove_lista(li, matri);
            printf("Matricula removida com sucesso!!\n");
            system("pause");
            break;
        case 5:
            li = cria_lista();
            printf("Lista criada com sucesso!!\n");
            system("pause");
            break;
        case 6:
            for(int i = 0,j = tamanho_lista(li) + 1; i < 5; i++)
            {
                for(int k = 0, l = 0; k < sizeof(dados.nome); k++)
                {
                    dados.nome[l] = NULL;
                    l++;
                }
                dados.matricula = j;
                dados.nome[0] = 'A';
                dados.nome[1] = 'l';
                dados.nome[2] = 'u';
                dados.nome[3] = 'n';
                dados.nome[4] = 'o';
                dados.n1 = 10;
                dados.n2 = 10;
                dados.n3 = 10;
                insere_lista_ordenada(li, dados);
                j++;
            }
            printf("Elementos adicionados com sucesso!!\n");
            system("pause");
            break;
        case 7:
            if(lista_vazia(li)){
                printf("\nLista Vazia...\n");
                system("pause");
                break;
            }
            libera_lista(li);
            li = cria_lista();
            printf("Lista liberada com sucesso!!\n");
            system("pause");
            break;
        case 8:
            if(lista_vazia(li)){
                printf("\nLista Vazia...\n");
                system("pause");
                break;
            }
            printf("A lista possui %d elementos!\n", tamanho_lista(li));
            system("pause");
            break;
        case 9:
            if(lista_vazia(li)){
                printf("\nLista Vazia...\n");
                system("pause");
                break;
            }
            imprime_lista(li);
            system("pause");
            break;
        case 10:
            printf("Digite a Matricula: ");
            scanf("%d", &dados.matricula);
            printf("Digite o Nome: ");
            fseek(stdin,0,SEEK_END);
            scanf("%s", dados.nome);
            printf("Digite a Nota 01: ");
            scanf("%f", &dados.n1);
            printf("Digite a Nota 02: ");
            scanf("%f", &dados.n2);
            printf("Digite a Nota 03: ");
            scanf("%f", &dados.n3);
            insere_lista_inicio(li, dados);
            printf("Elemento inserido no inicio da lista\n");
            system("pause");
            break;
        case 11:
            if(lista_vazia(li)){
                printf("\nLista Vazia...\n");
                system("pause");
                break;
            }
            remove_lista_inicio(li);
            printf("Elemento do inicio da lista removido!!\n");
            system("pause");
            break;
        case 12:
            printf("Digite a Matricula: ");
            scanf("%d", &dados.matricula);
            printf("Digite o Nome: ");
            fseek(stdin,0,SEEK_END);
            scanf("%s", dados.nome);
            printf("Digite a Nota 01: ");
            scanf("%f", &dados.n1);
            printf("Digite a Nota 02: ");
            scanf("%f", &dados.n2);
            printf("Digite a Nota 03: ");
            scanf("%f", &dados.n3);
            insere_lista_final(li, dados);
            printf("Elemento inserido no final da lista\n");
            system("pause");
            break;
        case 13:
            if(lista_vazia(li)){
                printf("\nLista Vazia...\n");
                system("pause");
                break;
            }
            remove_lista_final(li);
            printf("Elemento do final da lista removido!!\n");
            system("pause");
            break;
        case 14:
            if(lista_vazia(li)){
                printf("\nLista Vazia...\n");
                system("pause");
                break;
            }
            printf("Qual elemento deseja remover? ");
            scanf("%d", &matri);
            remove_lista(li, matri);
            printf("Elemento da lista removido com sucesso!!\n");
            system("pause");
            break;
        case 15:
            if(lista_vazia(li)){
                printf("\nLista Vazia...\n");
                system("pause");
                break;
            }
            printf("Qual posicao deseja consultar? ");
            scanf("%d", &matri);
            consulta_lista_pos(li, matri, &dados);
            printf("\nMatricula: %d", dados.matricula);
            printf("\nNome: %s", dados.nome);
            printf("\nNotas: %.2f %.2f %.2f\n", dados.n1, dados.n2, dados.n3);
            system("pause");
            break;
        case 16:
            if(lista_vazia(li)){
                printf("\nLista Vazia...\n");
                system("pause");
                break;
            }
            printf("Qual matricula deseja consultar? ");
            scanf("%d", &matri);
            consulta_lista_mat(li, matri, &dados);
            printf("\nMatricula: %d", dados.matricula);
            printf("\nNome: %s", dados.nome);
            printf("\nNotas: %.2f %.2f %.2f\n",dados.n1, dados.n2, dados.n3);
            system("pause");
            break;
        case 0:
            con = false;
            break;
        default:
            printf("\nOpcao Desconhecida\n");
            system("pause");
            break;
        }
    }
    return 0;
}
