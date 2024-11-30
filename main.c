#include <stdio.h>
#include <stdlib.h>

#include "Estruturas/sabor.h"
#include "Estruturas/tipo.h"
#include "Estruturas/pedido.h"

int main() {
    // Criação das listas de tipos e sabores
    ListaTipo *lista_tipos = construtor_lista_tipo();
    ListaSabores *lista_sabores = construtor_lista_sabores();

    // Adicionando tipos à lista
    add_tipo(lista_tipos, 1, "Tradicional", 10.0);
    add_tipo(lista_tipos, 2, "Especial", 15.0);
    add_tipo(lista_tipos, 3, "Nobre", 20.0);

    // Listando os tipos disponíveis
    // printf("\n--- Lista de Tipos ---\n");
    // for (int i = 0; i < lista_tipos->tamanho; i++) {
    //     Tipo *tipo = get_tipo(lista_tipos, i);
    //     printf("ID: %d, Nome: %s, Valor: %.2f\n", tipo->id, tipo->nome, tipo->valor);
    // }

    // Adicionando sabores à lista
    add_sabor(lista_sabores, 101, "Mussarela", 1); 
    add_sabor(lista_sabores, 102, "Calabresa", 1); 
    add_sabor(lista_sabores, 103, "Frango com Catupiry", 2); 

    

    // Listando os sabores disponíveis
    printf("\n--- Lista de Sabores ---\n");
    
    for (int i = 0; i < lista_sabores->tamanho; i++) {

        Sabor *sabores = get_sabor(lista_sabores, i);

        printf("Código: %d, Nome: %s, Tipo: %i \n", sabores->cod, sabores->nome, sabores->tipo);
        
    }

    ListaPizza *lista_pizzas = construtor_lista_pizza();
    add_pizza(lista_pizzas, 1, "Mussarela, FrangoCatupiry", "M", )
    // Liberar memória
    liberar_lista_tipos(lista_tipos);
    liberar_lista_sabores(lista_sabores);
}
