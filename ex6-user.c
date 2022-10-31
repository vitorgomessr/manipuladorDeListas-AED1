#include <stdio.h>
#include <stdlib.h>
#include "ex6-TAD.h"

int
main()
{
  int guard = 0;            // contador de listas
  int op;
  lista A;
  lista B;
  int elem;

  int oplist;
  int pos;
  int cont1 = 0;
  int i;

    printf("-=-=-=-=-=-=-=-=-=-=-=-MENU-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("[0] Criar lista\n");
    printf("[1] Inserir elemento\n");
    printf("[2] Remover elemento\n");
    printf("[3] Imprimir elemento\n");
    printf("[4] Imprimir lista\n");
    printf("[5] Apagar lista\n");
    printf("[6] Remover maior elemento\n");
    printf("[7] Remover pares\n");
    printf("[8] Inserir posicionado\n");
    printf("[9] Inverter lista\n");
    printf("[10] Encerrar programa\n");

  do
  {
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");

    printf("DIGITE UM COMANDO: ");

    if(scanf("%d", &op) != 1)
    {
        op = 15;        // indica erro
    }

    setbuf(stdin, NULL);

    if(op==0)                       // criar lista
    {
        if(guard==0)
        {
            A = cria_lista();
            guard++;
            printf("LISTA 1 CRIADA COM SUCESSO\n");
        }
        else
        {
            printf("APENAS UMA LISTA PODE SER CRIADA\n");
        }
    }

    else if(op==1)                  // inserir elemento
    {
        if(guard == 0)
        {
            printf("CRIE UMA LISTA ANTES DE INSERIR ELEMENTOS\n");
        }
        else
        {
            printf("DIGITE O CARACTER A SER INSERIDO: ");
            if(scanf("%d", &elem) != 1)
            {
                printf("DIGITE UM DADO DO TIPO INTEIRO\n");
                setbuf(stdin, NULL);
            }
            else
            {
                insere_elem(&A, elem);
                printf("ELEMENTO INSERIDO COM SUCESSO\n");
                cont1++;
            }
        }
    }

    else if(op==2)                  // remover elemento
    {
        if(guard == 1)
        {
            if(lista_vazia(A)!=1)
            {
                printf("DIGITE O CARACTER A SER REMOVIDO: ");

                if(scanf("%d", &elem) != 1)
                {
                    printf("DIGITE UM DADO DO TIPO INTEIRO\n");
                    setbuf(stdin, NULL);
                }

                if(remove_elem(&A, elem)==0)
                {
                    printf("FALHA AO REMOVER ELEMENTO\n");
                }
                else
                {
                    printf("CARACTER %d REMOVIDO\n", elem);
                    cont1--;
                }
            }
            else
            {
                printf("LISTA VAZIA\n");
            }
        }
        else
        {
            printf("LISTA INEXISTENTE!\n");
        }
    }

    else if(op==3)                      // imprimir elemento
    {
        if(guard == 1)
        {
            if(lista_vazia(A)!=1)
            {
                printf("DIGITE A POSICÃO NA LISTA: ");
                scanf("%d", &pos);

                if(pos<=cont1 && pos > 0)
                {
                    printf("O %dº ELEMENTO NA 1ª LISTA É %d\n", pos, get_elem_pos(A, pos));
                }
                else
                {
                    printf("POSICÃO INVÁLIDA!\n");
                }
                setbuf(stdin, NULL);
            }
            else
            {
                printf("LISTA VAZIA\n");
            }
        }
        else
        {
            printf("NÃO HÁ REGISTRO DE LISTA\n");
        }
    }

    else if(op==4)                      // imprimir lista
    {
        if(guard==0)
        {
            printf("NÃO HÁ REGISTRO DE LISTA CRIADO\n");
        }

        else if(guard==1)
        {
            if(lista_vazia(A) != 1)
            {
                for(i=1; i<=cont1; i++)
                {
                  printf("%d\n", get_elem_pos(A, i));
                }
            }
            else
            {
               printf("LISTA VAZIA!\n");
            }
        }
        setbuf(stdin, NULL);
    }

    else if(op==5)                  // apagar listas
    {
        if(guard==1)
        {
            apaga_lista(&A);
            printf("LISTA APAGADA\n");
            guard--;
        }

        else
        {
            printf("NÃO HÁ REGISTRO DE LISTA!\n");
        }
    }

    else if(op==6)                  // remover maior elemento
    {
        int maior;
        setbuf(stdin,NULL);

        if(guard==1)
        {
            if(lista_vazia(A)!=1)
            {
                maior = remove_maior(&A);
                printf("%d FOI REMOVIDO\n", maior);
                cont1--;
            }
            else
            {
                printf("LISTA VAZIA!\n");
            }
        }
        else
        {
            printf("CRIE UMA LISTA PRIMEIRO\n");
        }
    }

    else if(op==7)
    {
        int pares;
        if(guard==1)
        {
            if(lista_vazia(A)!=1)
            {
                if((pares = remove_pares(&A))>0)
                {
                    printf("%d NÚMEROS PARES REMOVIDOS\n", pares);
                    cont1 = cont1 - pares;
                }
                else
                {
                    printf("NÃO HÁ PARES NA LISTA\n");
                }
            }
            else
            {
                printf("LISTA VAZIA\n");
            }
        }
        else
        {
            printf("LISTA INEXISTENTE\n");
        }
    }

    else if(op==8)
    {
        if(guard==1)
        {
            pos = 0;
            printf("DIGITE A POSIÇÃO QUE DESEJA INSERIR: ");
            scanf("%d", &pos);

            printf("DIGITE O CARACTER A SER INSERIDO: ");
            if(scanf("%d", &elem) != 1)
            {
                printf("DIGITE UM DADO DO TIPO INTEIRO\n");
                setbuf(stdin, NULL);
            }
            else
            {
                if(insere_posicao(&A, pos, elem) == 1)
                {
                    printf("ELEMENTO INSERIDO COM SUCESSO\n");
                    cont1++;
                }
                else
                {
                    printf("FALHA AO INSERIR ELEMENTO\n");
                    setbuf(stdin, NULL);
                }
            }
        }
        else
        {
            printf("CRIE UMA LISTA PRIMEIRO\n");
        }
    }

    else if(op==9)
    {
        if(guard==1)
        {
            if(lista_vazia(A)!=1)
            {
                lista B;
                B = cria_lista();
                if(inverte_lista(&A, &B)==1)
                {
                    for(i=1; i<=cont1; i++)
                    {
                        printf("%d\n", get_elem_pos(B, i));
                    }
                }
                else
                {
                    printf("FALHA AO INVERTER LISTA\n");
                }
            }
            else
            {
                printf("LISTA VAZIA\n");
            }
        }
        else
        {
            printf("CRIE UMA LISTA PRIMEIRO\n");
        }
    }

    else if(op==10)         // encerra programa
    {
        break;
    }

    else
    {
        printf("COMANDO INVÁLIDO!\n");
    }
    setbuf(stdin,NULL);

  }while(op!=10);

    printf("PROGRAMA FINALIZADO, VOLTE SEMPRE!\n");

    return 0;
}
