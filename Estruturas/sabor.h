#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#ifndef SABOR_H
#define SABOR_H

typedef struct Sabor {
    int cod;
    char nome[50];
    char tipo[50]; // Tipo do sabor: tradicional, especial, nobre
    float preco; 
} Sabor;

Sabor construtor_sabor(int cod,  char nome[],  char tipo[], float preco) {
    Sabor novo;

    novo.cod = cod;
    strcpy(novo.nome, nome);
    strcpy(novo.tipo, tipo);
    novo.preco = preco;

    return novo;
}

typedef struct ListaSabores {
    Sabor *array;
    int tamanho;   
    int capacidade; 
} ListaSabores;


ListaSabores *construtor_lista_sabores() {
    ListaSabores *nova_lista = (ListaSabores *)malloc(sizeof(ListaSabores));

    nova_lista->tamanho = 0;
    nova_lista->capacidade = 0;
    nova_lista->array = NULL;


    return nova_lista;
}

void add_sabor(ListaSabores *lista, int cod, const char nome[], const char tipo[], float preco) {
    Sabor novo_sabor =  construtor_sabor(cod, nome, tipo, preco);

    if (lista->array == NULL) {
        lista->capacidade = 2;
        lista->array =  (Sabor *)malloc(lista->capacidade * sizeof(Sabor));
    }

    if (lista->tamanho == lista->capacidade) {
        lista->capacidade *= 2;
        Sabor *novo_array = (Sabor *)realloc(lista->array, lista->capacidade*sizeof(Sabor));
        lista->array = novo_array;
    }

    lista->array[lista->tamanho++] = novo_sabor;
}

Sabor *get_sabor(ListaSabores *lista, int index) {

    if (lista == NULL || index < 0 || index >= lista->tamanho) {
        return NULL;
    }

    return &lista->array[index];
}


Sabor *get_sabor_id(ListaSabores *lista, int id) {

    for(int i = 0; i < lista->tamanho; i++){
        if(id == lista->array[i].cod){
            return &lista->array[i];
        }
    }
    
    return NULL;
}

void liberar_lista_sabores(ListaSabores *lista) {
    if (lista != NULL) {
        free(lista->array);
        free(lista);
    }
}

#endif
