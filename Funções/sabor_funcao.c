#include <stdio.h>
#include "sabor.h";
#include "tipo_funcao.c"

#ifndef sabor_funcao
#define sabor_funcao

int menu_sabor(int user){

    if (user == 0){
        int op;


        printf("\n --------------------------------------------");
        printf("\n|------- 1 - Inserir um novo sabor----------|");
        printf("\n|------- 2 - Ver sabores -------------------|");
        printf("\n --------------------------------------------");

        printf("\nDigite a opcao desejada: ");
        scanf("%i", &op);

        if(op < 0 || op > 2){
            printf("Digite uma opcao valida!");
        }

        return op;
    }

}

void adicionar_sabor(ListaSabores * array, int cod, ListaTipo * tipo_array){
    int cod;
    char nome;
    int tipo;

    printf("\n ------------ CADASTRAR NOVO SABOR ----------\n");
    printf("\nNome: ");
    fflush(stdin);
    gets(nome);

    printf("\nTipo: ");
    ver_tipo(tipo_array);
    printf("\n\n ID tipo: ");
    fflush(stdin);
    gets(tipo);

}

#endif
