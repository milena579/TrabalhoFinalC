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
}

// Função que adiciona uma nova pizza no array de pizzas
void adicionar_pizza(ListaPizza * array, ListaSabores * sabores, int id){
    
    char nome[50] = "pizza";
    char tamanho[1];
    int id_sabor;
    float valor;
    float maior_sabor = 0.0f;

    printf("\n ------------ ADICIONAR PIZZA ----------\n");

    printf("\nTamanho (P, M, G): ");
    fflush(stdin);
    gets(tamanho);

    ListaSabores *lista_sabores = construtor_lista_sabores();
    printf("\n--- Lista de Sabores ---\n");
    
    for (int i = 0; i < lista_sabores->tamanho; i++) {
        Sabor *sabores = get_sabor(lista_sabores, i);
        printf("Código: %d, Nome: %s, Tipo: %i \n, Preço: %f", sabores->cod, sabores->nome, sabores->tipo, sabores->preco);   
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
        printf("\nID do Sabor %i: ", i + 1);
        scanf("%d", &id_sabor);

        Sabor *sabor = get_sabor(lista_sabores, id_sabor - 1); 
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

    add_pizza(array, id, nome, tamanho, id_sabor, valor);
}

//mostra uma lista com todas as pizzas cadastradas
void ver_pizzas(ListaPizza * array){

    printf("\n-------- LISTA DE PIZZAS ---------\n");

    for(int i = 0; i < array->tamanho; i ++){

        Pizza *pizzas = get_pizza(array, i);
        
        printf("\n| %i |", pizzas->id);
        printf("\n| %s |", pizzas->nome);
        printf("\n| %s |", pizzas->tamanho);
        printf("\n| %i |", pizzas->id_sabor);
        printf("\n| %f |", pizzas->valor);
    }
}


#endif

        