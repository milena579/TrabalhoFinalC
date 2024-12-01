#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sabor.h"
#include "tipo.h"

#ifndef pizza
#define pizza

typedef struct Pizza {
    int id;
    char nome[50];
    char tamanho[15];
    int id_sabor[3]; //pensei em deixar os id em um vetor de até 3 sabores
    float valor;
} Pizza;

typedef struct ListaPizza {
    Pizza * array;
    int tamanho;
    int capacidade;
} ListaPizza;

//função que será chamada na main para declarar uma pizza
Pizza construtor_pizza(int id, char nome[], char tamanho[], int id_sabor[3], float valor)
{
    Pizza novaPizza;

    novaPizza.id = id;
    strcpy(novaPizza.nome, nome); //Quando se quiser copiar o conteúdo de uma string para outro se deve utilizar a função strcpy
    
    //Aqui pensei em pesquisar o id do sabor, depois o tipo do sabor e por fim, o valor daquele tipo
    // afim de adicionar ele ao valor da pizza

    Sabor *sabores = get_sabor(ListaSabores, id_sabor[0])
    int tipo = sabores->tipo;

    Tipo *tipoSabor = get_tipo(ListaTipo, tipo);

    float valorTipo = tipoSabor->valor;

    if(tamanho == "P" || tamanho == "p"){
        novaPizza.valor = valor + (valor * 0.10);
    } else if (tamanho == "M" || tamanho == "m"){
        novaPizza.valor = valor + (valor * 0.18);
    } else{
        novaPizza.valor = valor + (valor * 0.25);
    }

    strcpy(novaPizza.tamanho, tamanho);
    strcpy(novaPizza.id_sabor, id_sabor);

    return novaPizza;
}

ListaPizza * construtor_lista_pizza() {
    ListaPizza * novo = (ListaPizza*) malloc (sizeof(ListaPizza)); //define o tamanho do array como o tamanho atual da lista
    novo->tamanho = 0;
    novo->capacidade = 0;
    novo->array = NULL;

    return novo;
}

void add_pizza(ListaPizza * array, int id, char nome[], char tamanho[], char id_sabor[],  float valor){

    Pizza nova_pizza = construtor_pizza(id, nome, tamanho, id_sabor, valor);

    if( array->array == NULL){
        array->capacidade = 2;
        array->array = (Pizza*)malloc(array->capacidade*sizeof(Pizza));
    }

    if(array->tamanho == array->capacidade){
        array->capacidade *=2;
        array->array = (Pizza*)realloc(array->array, array->capacidade*sizeof(Pizza));
    }

    array->array[array->tamanho++] = nova_pizza;
}

Pizza * get_pizza(ListaPizza * array, int index) {

    if(index >= array->tamanho || index < 0){
        return NULL;
    }

    return &array->array[index];
}

#endif