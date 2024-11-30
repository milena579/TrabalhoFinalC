#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Estruturas/pizza.h"
#include "../Estruturas/sabor.h"
#include "../Estruturas/tipo.h"

#ifndef pizza_funcao
#define pizza_funcao

int menu_pizza(int user){

    //verifica se é adm
    if (user == 0){
        int op;

        printf("\n --------------------------------------------");
        printf("\n|------- 1 - Inserir uma nova pizza----------|");
        printf("\n|------- 2 - Ver pizza ----------------------|");
        printf("\n --------------------------------------------");

        printf("\nDigite a opcao desejada: ");
        scanf("%i", &op);

        if(op < 0 || op > 2){
            printf("Digite uma opcao valida!");
        }

        return op;
    }

}

// Função que adiciona uma nova pizza no array de pizzas
void adicionar_pizza(ListaPizza * array, int id){
    
    char nome[50];
    char tamanho[15];
    int id_sabor;
    int id_tipo;
    float valor;

    // char new_sabor_id[20] = get_sabor(array_sabores, id_sabor);
    // char new_tipo_id[20] = get_tipo(array_tipos, id_tipo);
    
    printf("\n ------------ ADICIONAR PIZZA ----------\n");
    printf("\nNome: ");
    fflush(stdin);
    gets(nome);

    printf("\nTamanho: ");
    fflush(stdin);
    gets(tamanho);

    printf("\nID do Sabor:");
    scanf("%i", &id_sabor);
    // vai repetir a pergunta até obter um valor correto
    while(id_sabor < 101 || id_sabor > 103) {
        printf("\nValor invalido! ID do Sabor:");
    scanf("%i", &id_sabor);
    }

    printf("\nID do Tipo:");
    scanf("%i", &id_tipo);
    // vai repetir a pergunta até obter um valor correto
    while(id_tipo < 1 || id_tipo > 3) {
        printf("\nValor invalido! ID do Tipo:");
        scanf("%i", &id_tipo);
    }

    printf("\nValor: ");
    scanf("%f", &valor);

    add_pizza(array, id, nome, tamanho, id_sabor, id_tipo, valor);

}

//mostra uma lista com todas as pizzas cadastradas
void ver_pizzas(ListaPizza * array){

    printf("\n-------- LISTA DE PIZZAS ---------\n");

    for(int i = 0; i < array->tamanho; i ++){

        Pizza * pizzas = get_pizza(array, i);
        
        printf("\n| %i |", pizzas->id);
        printf("\n| %s |", pizzas->nome);
        printf("\n| %s |", pizzas->tamanho);
        printf("\n| %s |", pizzas->id_sabor);
        printf("\n| %s |", pizzas->id_tipo);
        printf("\n| %f |", pizzas->valor);
    }
}


#endif

        