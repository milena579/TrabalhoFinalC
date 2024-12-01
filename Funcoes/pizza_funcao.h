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
void adicionar_pizza(ListaPizza * array, ListaSabores * sabores, ListaTipo * tipo, int id){
    
    char nome[50] = "pizza";
    char tamanho[1];
    int id_sabor[3];
    float valor = 0;

    // char new_sabor_id[20] = get_sabor(array_sabores, id_sabor);
    // char new_tipo_id[20] = get_tipo(array_tipos, id_tipo);
    
    printf("\n ------------ ADICIONAR PIZZA ----------\n");

    printf("\nTamanho (P, M, G): ");
    fflush(stdin);
    gets(tamanho);

    ListaSabores *lista_sabores = construtor_lista_sabores();
    printf("\n--- Lista de Sabores ---\n");
    
    for (int i = 0; i < lista_sabores->tamanho; i++) {
        Sabor *sabores = get_sabor(lista_sabores, i);
        printf("Codigo: %d, Nome: %s, Tipo: %i \n", sabores->cod, sabores->nome, sabores->tipo);   
    }

    //pensando em facilitar, pensei em deixar que a pizza P tem um sabor apenas, a M 2 e G 3
    
    int qtdSabores = 1;

    if(tamanho == "M" || tamanho == "g"){
        qtdSabores = 2;
    }
    if(tamanho == "G" || tamanho == "g"){
        qtdSabores = 3;
    }

    for(int i = 0; i < qtdSabores; i++){
        printf("\nID do Sabor %i: ", i+1);
        scanf("%i", &id_sabor[i]);

        // vai repetir a pergunta até obter um valor correto
        while(id_sabor < 101 || id_sabor > 103) {
            printf("\nValor invalido! ID do Sabor:");
            scanf("%i", &id_sabor[i]);
        }

    }

    printf("\nValor: ");
    scanf("%f", &valor);

    add_pizza(array, sabores, tipo, id, nome, tamanho, id_sabor, valor);

}

//mostra uma lista com todas as pizzas cadastradas
void ver_pizzas(ListaPizza * array){

    printf("\n-------- LISTA DE PIZZAS ---------\n");

    for(int i = 0; i < array->tamanho; i ++){

        Pizza * pizzas = get_pizza(array, i);
        
        printf("\n| %i |", pizzas->id);
        printf("\n| %s |", pizzas->nome);
        printf("\n| %s |", pizzas->tamanho);
        printf("\n| %i |", pizzas->id_sabor);
        printf("\n| %f |", pizzas->valor);
    }
}


#endif

        