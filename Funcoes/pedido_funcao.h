#include <stdio.h>
#include <string.h>
#include "../Estruturas/pizza.h"
#include "../Estruturas/pedido.h"
#include "../Funcoes/pizza_funcao.h"

#ifndef funcao_pedido
#define funcao_pedido

int menu_pedido(){
    int op;

    printf("\n --------------------------------------------");
    printf("\n|------- 0 - Cancelar pedido ----------------|");
    printf("\n|------- 1 - Inserir pizza ------------------|");
    printf("\n|------- 2 - Finalizar pedido ---------------|");
    printf("\n --------------------------------------------");

    printf("\nDigite a opcao desejada: ");
    scanf("%i", &op);

    if(op < 0 || op > 2){
        printf("Digite uma opcao valida!");
    }

    return op;

}

void novoPedido(ListaPedido * pedido, ListaSabores * lista_sabores) {

    int cod;
    char nomeCliente[20];
    ListaPizza pizzas;
    float total;

    ListaPizza * lista_pizzas = construtor_lista_pizza();

    printf("\n ------------ REGISTRAR PEDIDO ----------\n");
    printf("\nDigite o seu nome: ");
    scanf("%s", &nomeCliente);

    menu_pedido();
    printf("")

    
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