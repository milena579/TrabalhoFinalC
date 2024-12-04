#include <stdio.h>
#include <string.h>
#include "../Estruturas/pizza.h"
#include "../Estruturas/pedido.h"
#include "../Funcoes/pizza_funcao.h"

#ifndef funcao_pedido
#define funcao_pedido

//Função para exibir o pedido
void exibirPedido(Pedido pedido, ListaSabores * sabores) {

    for(int i = 0; i < pedido.pizzas->tamanho; i++) {

        Pizza *pizzas = get_pizza(pedido.pizzas, i);
        pedido.total = pizzas->valor + pedido.total;
    }

    pedido.quantidadePizzas = pedido.pizzas->tamanho;

    printf("\n\n--------------------- PEDIDO ---------------------\n");
    printf("\nCliente: %s\n", pedido.nomeCliente);
    ver_pizzas(pedido.pizzas, sabores);
    printf("\n\nQuantidade de pizzas: %i", pedido.quantidadePizzas);
    printf("\n\nValor total: %.2f", pedido.total);
    printf("\nCOD: %i", pedido.cod);
    printf("\n----------------------------------------------------\n");

}

void gerar_comprovante(Pedido pedido, ListaSabores * sabores) {

    FILE * arquivo_pedido = fopen("pedido.txt", "w"); // Cria o arquivo de pedidos

    fprintf(arquivo_pedido, "COD: %d\n", pedido.cod);
    fprintf(arquivo_pedido, "Cliente: %s\n", pedido.nomeCliente);

    for(int i = 0; i < pedido.pizzas->tamanho; i++){

        Pizza *pizzas = get_pizza(pedido.pizzas, i);

        fprintf(arquivo_pedido, "\n| ID: %i ", pizzas->id);
        fprintf(arquivo_pedido, " | %s ( %s ) |", pizzas->nome, pizzas->tamanho);
        
        for (int i = 0; i < 3; i++)
        {
            if(pizzas->id_sabor[i]) {
                Sabor * sabor = get_sabor_id(sabores, pizzas->id_sabor[i]);
                fprintf(arquivo_pedido, " %s,", sabor->nome);
            }
        }
        
        // fprintf(" | %.2f |", pizzas->valor);
    }

    fprintf(arquivo_pedido, "Preço Total: R$ %.2f\n", pedido.total);
    fclose(arquivo_pedido); 
}

int menu_pedido(Pedido pedido, ListaPizza * lista_pizzas, ListaSabores * lista_sabores) {
    
    int op = 3;

    while (op == 3)
    {
        printf("\n\n|------------OPCOES:-------------------------|");
        printf("\n|--------------------------------------------|");
        printf("\n|------- 0 - Cancelar pedido ----------------|");
        printf("\n|------- 1 - Inserir pizza ------------------|");
        printf("\n|------- 2 - Finalizar pedido ---------------|");
        printf("\n|--------------------------------------------|");

        printf("\n\nDigite a opcao desejada: \n");
        scanf("%i", &op);

        switch (op)
        {
            case 0:
                printf("\nPedido cancelado!");
                break;

            case 1:
                adicionar_pizza(pedido.pizzas, lista_sabores, pedido.pizzas->tamanho+1);
                break;

            case 2:
                printf("\nPedido finalizado!");
                exibirPedido(pedido, lista_sabores);
                gerar_comprovante(pedido, lista_sabores);
                break;
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


    printf("\n ------------ REGISTRAR PEDIDO ----------\n");
    printf("\nDigite o seu nome: ");
    scanf("%s", &nomeCliente);

    Pedido pedido = construtor_pedido(1, nomeCliente, lista_pizzas, lista_pizzas->tamanho, total);

    int op = 1;

    while (op == 1)
    {
       op = menu_pedido(pedido, lista_pizzas->array, lista_sabores);
    }
}

#endif