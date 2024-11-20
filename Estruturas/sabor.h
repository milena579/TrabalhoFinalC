#include <stdio.h>
#include <stdlib.h>
#include "tipo.h";

typedef struct Sabor {
    int cod;
    char nome[50];
    int tipo  //tipo de sabor: tradicional, especial, nobre

} Sabor;

Sabor construtor_sabor(int cod, char nome[], int tipo){

    Sabor novo;

    novo.cod = cod;
    strcpy(novo.nome, nome); //Quando se quiser copiar o conteúdo de uma string para outro se deve utilizar a função strcpy
    strcpy(novo.tipo);

    return novo;
}

typedef struct ListaSabores {
    Sabor * array;
    int tamanho;
    int capacidade;

} ListaSabores;

ListaSabores *  construtos_lista_sabores(){
    ListaSabores * novo = (ListaSabores*)malloc(sizeof(ListaSabores));
    novo->tamanho = 0;
    novo->capacidade = 0;
    novo->array = NULL;

    return novo;
}

void add_sabor(ListaSabores * array, int cod, char nome[], int tipo){
    Sabor novo_sabor = construtor_sabor(cod, nome, tipo);

    if( array->array == NULL){
        array->capacidade = 2;
        array->array = (Sabor*)malloc(array->capacidade*sizeof(Sabor));
    }

    if(array->tamanho == array->capacidade){
        array->capacidade *=2;
        array->array = (Sabor*)realloc(array->array, array->capacidade*sizeof(Sabor));
    }

    array->array[array->tamanho++] = novo_sabor;
}

Sabor * get_sabor( ListaSabores * array, int index) {

    if(index >= array->tamanho || index < 0){
        return NULL;
    }

    return &array->array[index];
}