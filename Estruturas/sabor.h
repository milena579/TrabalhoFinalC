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

Sabor construtor_sabor(int cod, const char nome[], const char tipo[], float preco) {
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
    if (nova_lista == NULL) {
        perror("Falha ao alocar memória para ListaSabores");
        exit(EXIT_FAILURE);
    }

    nova_lista->tamanho = 0;
    nova_lista->capacidade = 2;
    nova_lista->array = (Sabor *)malloc(nova_lista->capacidade * sizeof(Sabor));

    if (nova_lista->array == NULL) {
        perror("Falha ao alocar memória para o array de sabores");
        free(nova_lista);
        exit(EXIT_FAILURE);
    }

    return nova_lista;
}

void add_sabor(ListaSabores *lista, int cod, const char nome[], const char tipo[], float preco) {
    if (lista == NULL) return;

    if (lista->tamanho == lista->capacidade) {
        lista->capacidade *= 2;
        Sabor *novo_array = (Sabor *)realloc(lista->array, lista->capacidade * sizeof(Sabor));
        lista->array = novo_array;
    }

    lista->array[lista->tamanho++] = construtor_sabor(cod, nome, tipo, preco);
}

Sabor *get_sabor(const ListaSabores *lista, int index) {
    if (lista == NULL || index < 0 || index >= lista->tamanho) {
        return NULL;
    }
    return &lista->array[index];
}

void liberar_lista_sabores(ListaSabores *lista) {
    if (lista != NULL) {
        free(lista->array);
        free(lista);
    }
}

#endif
