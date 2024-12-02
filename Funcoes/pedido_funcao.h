#include <stdio.h>
#include <string.h>
#include "../Estruturas/pizza.h"
#include "../Estruturas/pedido.h"
#include "../Funcoes/pizza_funcao.h"

#ifndef funcao_pedido
#define funcao_pedido

int menu_pedido(Pedido pedido, ListaPizza * lista_pizzas, ListaSabores * lista_sabores) {
    
    int op = 3;

    while (op == 3)
    {
        printf("\n --------------------------------------------");
        printf("\n|------- 0 - Cancelar pedido ----------------|");
        printf("\n|------- 1 - Inserir pizza ------------------|");
        printf("\n|------- 2 - Finalizar pedido ---------------|");
        printf("\n --------------------------------------------");

        printf("\nDigite a opcao desejada: ");
        scanf("%i", &op);

        switch (op)
        {
            case 0:
                printf("\nPedido cancelado!");
                break;

            case 1:
                adicionar_pizza(lista_pizzas, lista_sabores, lista_pizzas->tamanho-1);

            case 2:
                printf("Pedido finalizado!");
                exibirPedido(pedido);
        }

        if(op < 0 || op > 3){
            printf("\nDigite uma opcao valida!");
        }
    }
    
    return op;

}

void novoPedido(ListaSabores * lista_sabores) {

    int cod;
    char nomeCliente[20];
    ListaPizza pizzas;
    float total = 0;

    ListaPizza * lista_pizzas = construtor_lista_pizza();

    for(int i = 0; i < lista_pizzas->tamanho; i++) {
        Pizza *pizzas = get_pizza(lista_pizzas, i);
        total = pizzas->valor + total;
    }

    printf("\n ------------ REGISTRAR PEDIDO ----------\n");
    printf("\nDigite o seu nome: ");
    scanf("%s", &nomeCliente);

    Pedido pedido = construtor_pedido(1, nomeCliente, *lista_pizzas, lista_pizzas->tamanho, total);

    menu_pedido(pedido, lista_pizzas, lista_sabores);

    
}

//Função para exibir o pedido
void exibirPedido(Pedido pedido) {
    printf("\n ------------ PEDIDO ----------\n");
    printf("\nCliente: %s", pedido.nomeCliente);
    ver_pizzas(pedido.pizzas);
    printf("\nQuantidade: %i", pedido.quantidadePizzas);
    printf("\n\nValor total: %i", pedido.total);
    printf("\nCOD: %i", pedido.cod);
}

#endif