#include <stdio.h>
#include <string.h>
#include "pizza.h"
#include "../Funcoes/pizza_funcao.h"

#ifndef pedido
#define pedido

// Definição da estrutura do pedido
typedef struct Pedido {
    int cod;
    char nomeCliente[20];
    ListaPizza pizzas; 
    int quantidadePizzas;
    float total;
} Pedido;

typedef struct ListPedido {
    Pedido * array;
    int tamanho;
    int capacidade;
} ListaPedido;

//função que será chamada na main para declarar um pedido
Pedido construtor_pedido(int cod, char nomeCliente[], ListaPizza pizzas, int quantidadePizzas, float total)
{
    Pedido novoPedido;

    novoPedido.cod;
    strcpy(novoPedido.nomeCliente, nomeCliente);
    novoPedido.pizzas;
    novoPedido.quantidadePizzas;
    novoPedido.total;
}

ListaPedido * construtor_lista_pedido() {
    ListaPedido * novo = (ListaPedido*) malloc(sizeof(ListaPedido));
    novo->tamanho = 0;
    novo->capacidade = 0;
    novo->array = NULL;

    return novo;
}

// Função para registrar um pedido
void registrarPedido(ListaPedido * array, int cod, char nomeCliente[], ListaPizza pizzas, int quantidadePizzas, float total) {

    Pedido novo_pedido = construtor_pedido(cod, nomeCliente, pizzas, quantidadePizzas, total);

    if( array->array == NULL){
        array->capacidade = 2;
        array->array = (Pedido*)malloc(array->capacidade*sizeof(Pedido));
    }

    if(array->tamanho == array->capacidade){
        array->capacidade *=2;
        array->array = (Pedido*)realloc(array->array, array->capacidade*sizeof(Pedido));
    }

    array->array[array->tamanho++] = novo_pedido;
}

#endif