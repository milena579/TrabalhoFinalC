#include <stdio.h>
#include <stdlib.h>

typedef struct Tipo {
    int id;
    char nome[50];
    float valor;

} Tipo;

Tipo construtor_tipo(int id, char nome[], float valor){

    Tipo novoTipo;

    novoTipo.id = id;
    strcpy(novoTipo.nome, nome); //Quando se quiser copiar o conteúdo de uma string para outro se deve utilizar a função strcpy
    novoTipo.valor = valor;

    return novoTipo;
}

typedef struct ListaTipo {
    Tipo * array;
    int tamanho;
    int capacidade;

} ListaTipo;

ListaTipo *  contrutor_lista_tipo(){
    ListaTipo * novo = (ListaTipo*)malloc(sizeof(ListaTipo));
    novo->tamanho = 0;
    novo->capacidade = 0;
    novo->array = NULL;

    return novo;
}

void add_tipo(ListaTipo * array, int id, char nome[], float valor){

    Tipo novo_tipo = construtor_tipo(id, nome, valor);

    if( array->array == NULL){
        array->capacidade = 2;
        array->array = (Tipo*)malloc(array->capacidade*sizeof(Tipo));
    }

    if(array->tamanho == array->capacidade){
        array->capacidade *=2;
        array->array = (Tipo*)realloc(array->array, array->capacidade*sizeof(Tipo));
    }

    array->array[array->tamanho++] = novo_tipo;
}

Tipo * get_tipo( ListaTipo * array, int index) {

    if(index >= array->tamanho || index < 0){
        return NULL;
    }

    return &array->array[index];
}
