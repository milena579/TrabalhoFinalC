#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Estruturas/pizza.h"
#include "../Estruturas/sabor.h"

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
    return 0;
}

// Função que adiciona uma nova pizza no array de pizzas
void adicionar_pizza(ListaPizza * array, ListaSabores * lista_sabores, int id){
    
    char tamanho[5];
    int id_sabor[3] = {0, 0, 0};
    float valor;
    float maior_sabor = 0;

    printf("\n ------------ ADICIONAR PIZZA ----------\n");

    printf("\nTamanho (P, M, G): ");
    scanf("%s", &tamanho);

    printf("\n--- Lista de Sabores ---\n");
    
    for (int i = 0; i < lista_sabores->tamanho; i++) {
        Sabor *sabores = get_sabor(lista_sabores, i);
        printf("\nCodigo: %d | Nome: %s | Tipo: %s | Preco: %f", sabores->cod, sabores->nome, sabores->tipo, sabores->preco);   
    }

    //pensando em facilitar, pensei em deixar que a pizza P tem um sabor apenas, a M 2 e G 3
    int qtdSabores = 1;

    if (strcmp(tamanho, "M") == 0 || strcmp(tamanho, "m") == 0) {
        qtdSabores = 2;
    }
    if (strcmp(tamanho, "G") == 0 || strcmp(tamanho, "g") == 0) {
        qtdSabores = 3;
    }

   for (int i = 0; i < qtdSabores; i++) {
        printf("\n\nID do Sabor %i: ", i + 1);
        scanf("%i", &id_sabor[i]);

        Sabor *sabor = get_sabor_id(lista_sabores, id_sabor[i]); 

        if (sabor != NULL && sabor->preco > maior_sabor) {
            maior_sabor = sabor->preco;  
        }
    }

    valor = maior_sabor;

    // Se o tamanho for M, adiciona 10%
    if (strcmp(tamanho, "M") == 0 || strcmp(tamanho, "m") == 0) {
        valor *= 1.10;  // Adiciona 10%
    }
    // Se o tamanho for G, adiciona 20%
    else if (strcmp(tamanho, "G") == 0 || strcmp(tamanho, "g") == 0) {
        valor *= 1.20;  
    }

    printf("\nValor: %.2f", valor);
    
    add_pizza(array, id, "Pizza", tamanho, id_sabor, valor);
}

//mostra uma lista com todas as pizzas cadastradas
void ver_pizzas(ListaPizza * array, ListaSabores * sabores){

    printf("\nLISTA DE PIZZAS:");

    for(int i = 0; i < array->tamanho; i ++){

        Pizza *pizzas = get_pizza(array, i);

        printf("\n| ID: %i ", pizzas->id);
        printf(" | %s ( %s ) |", pizzas->nome, pizzas->tamanho);
        
        for (int i = 0; i < 3; i++)
        {
            if(pizzas->id_sabor[i] != NULL) {
                Sabor * sabor = get_sabor_id(sabores, pizzas->id_sabor[i]);
                printf(" %s,", sabor->nome);
            }
        }
        
        printf(" | %.2f |", pizzas->valor);
    }
}


#endif

        