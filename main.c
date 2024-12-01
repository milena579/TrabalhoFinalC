#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Estruturas/sabor.h"
#include "Estruturas/pedido.h"
#include "Funcoes/pizza_funcao.h"  // Certifique-se de incluir a função de adicionar pizza

int main() {

    ListaSabores *lista_sabores = construtor_lista_sabores();


    add_sabor(lista_sabores, 101, "Mussarela", "Clássica", 29.90); 
    add_sabor(lista_sabores, 102, "Calabresa", "Clássica", 29.90); 
    add_sabor(lista_sabores, 103, "Frango com Catupiry", "Especial", 34.90); 

    printf("\n--- Lista de Sabores ---\n");
    for (int i = 0; i < lista_sabores->tamanho; i++) {
        Sabor *sabores = get_sabor(lista_sabores, i);
        printf("Código: %d, Nome: %s, Tipo: %s, Preço: %.2f\n", sabores->cod, sabores->nome, sabores->tipo, sabores->preco);
    }

    ListaPizza *lista_pizzas = construtor_lista_pizza();

    // Adicionando uma pizza de exemplo com 2 sabores para tamanho M
    int sabores_m[] = {101, 103}; 
    add_pizza(lista_pizzas, 1, "Mussarela, Frango com Catupiry", "M", sabores_m, 0);  

    // Exibindo as pizzas cadastradas
    printf("\n--- Lista de Pizzas ---\n");
    ver_pizzas(lista_pizzas);


    liberar_lista_sabores(lista_sabores);
    liberar_lista_pizzas(lista_pizzas);

    return 0;
}
