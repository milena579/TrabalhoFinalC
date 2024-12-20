#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Estruturas/sabor.h"
#include "Estruturas/pedido.h"
#include "Funcoes/pizza_funcao.h"  // Certifique-se de incluir a função de adicionar pizza
#include "Funcoes/pedido_funcao.h"  

int main() {

    ListaSabores *lista_sabores = construtor_lista_sabores();

    add_sabor(lista_sabores, 101, "Mussarela", "Classica", 29.90); 
    add_sabor(lista_sabores, 102, "Calabresa", "Classica", 29.90); 
    add_sabor(lista_sabores, 103, "Frango com Catupiry", "Especial", 34.90); 

    printf("\n--- Lista de Sabores ---\n");
    for (int i = 0; i < lista_sabores->tamanho; i++) {
        Sabor *sabores = get_sabor(lista_sabores, i);
        printf("Codigo: %d, Nome: %s, Tipo: %s, Preco: %.2f\n", sabores->cod, sabores->nome, sabores->tipo, sabores->preco);
    }

    novoPedido(lista_sabores);
    liberar_lista_sabores(lista_sabores);

    return 0;
}
