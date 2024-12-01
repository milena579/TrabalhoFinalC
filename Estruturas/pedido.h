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

// Função para registrar um pedido
void registrarPedido(ListaSabores * lista_sabores, ListaTipo * lista_tipos) {

    int cod;
    char nomeCliente[20];
    ListaPizza pizzas;
    int quantidadePizzas;
    float total;

    ListaPizza * lista_pizzas = construtor_lista_pizza();
    Pedido pedidos = construtor_pedido(cod, nomeCliente, pizzas, quantidadePizzas, total);
    
    printf("\n--- Registrar Pedido ---\n");
    printf("\nDigite o seu nome: ");
    scanf("%s", &pedidos.nomeCliente);
    printf("\nDigite o numero de pizzas que serão adicionadas: ");
    scanf("%d", &pedidos.quantidadePizzas);

    // Registrar as pizzas
    pedidos.total = 0;
    for (int i = 0; i < pedidos.quantidadePizzas; i++) {
        adicionar_pizza(lista_pizzas, lista_sabores, lista_tipos, i+1);
    }
}

// Função para exibir o pedido
// void exibirPedido(struct Pedido pedido) {
//     printf("\n--- Detalhes do Pedido ---\n");
//     printf("Cliente: %s\n", pedido.nomeCliente);
//     printf("\nPizzas do Pedido:\n");
//     for (int i = 0; i < pedido.quantidadePizzas; i++) {
//         printf("Pizza %d: %s (Tamanho: %c) - R$%.2f\n", i + 1, pedido.pizzas[i].nome, pedido.pizzas[i].tamanho, pedido.pizzas[i].preco);
//     }
//     printf("\nTotal do Pedido: R$%.2f\n", pedido.total);
// }

#endif