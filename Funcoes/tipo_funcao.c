#include <stdio.h>
#include "tipo.h"

#ifndef tipo_funcao
#define tipo_funcao

int menu_sabor(int user){

    if (user == 0){
        int op;


        printf("\n --------------------------------------------");
        printf("\n|------- 1 - Inserir um novo tipo----------|");
        printf("\n|------- 2 - Ver tipo de pizza ------------|");
        printf("\n --------------------------------------------");

        printf("\nDigite a opcao desejada: ");
        scanf("%i", &op);

        if(op < 0 || op > 2){
            printf("Digite uma opcao valida!");
        }

        return op;
    }

}

void adicionar_tipo(ListaTipo * array, int id){
    char nome;
    float valor;

    printf("\n ------------ CADASTRAR NOVO TIPO ----------\n");
    printf("\nNome: ");
    fflush(stdin);
    gets(nome);

    printf("\nTipo: ");
    scanf("%f", &valor);

    add_tipo(array, id, nome, valor);

}

void ver_tipo( ListaTipo * array){
    printf("\n-------- LISTA DE TIPOS ---------\n");

    for(int i = 0; i < array->tamanho; i ++){

        Tipo * tipo = get_tipo(array, i);

        printf("\n| %i |", tipo->id);
        printf("\n| %s |", tipo->nome);
        printf("\n| %f |", tipo->valor);
    }
}

#endif