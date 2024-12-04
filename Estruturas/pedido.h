#include <stdio.h>
#include <string.h>
#include "../Funcoes/pizza_funcao.h"
#include "pizza.h"

#ifndef struct_pedido
#define struct_pedido


typedef struct Pedido {
    int cod;
    char nomeCliente[20];
    ListaPizza * pizzas; 
    int quantidadePizzas;
    float total;

} Pedido;

Pedido construtor_pedido(int cod, char nomeCliente[], ListaPizza *pizzas, int quantidadePizzas, float total)
{
    Pedido novoPedido;

    novoPedido.cod = cod;
    strcpy(novoPedido.nomeCliente, nomeCliente);
    novoPedido.pizzas = pizzas;
    novoPedido.quantidadePizzas=quantidadePizzas;
    novoPedido.total=total;

    return novoPedido;
}

#endif