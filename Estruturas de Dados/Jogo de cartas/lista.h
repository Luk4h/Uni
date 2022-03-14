//lista.h

#ifndef LISTA_H
#define LISTA_H

template<typename T>
struct TElemento {
    T dado;
};

template<typename TIPO, int CAPACIDADE>
struct TListaEstatica {
    TElemento<TIPO> vetor[CAPACIDADE];
    int quantidade;
};

template <typename T, int MAX>
void inicializar_lista_estatica(TListaEstatica<T, MAX> &l){
    l.quantidade = 0;
}

template <typename T, int MAX>
void inserir_fim_lista_estatica(TListaEstatica<T,MAX> &l, T c) {
    if(l.quantidade >= MAX) {
        throw "List Overflow";
    }
    TElemento<T> container;
    container.dado = c;
    l.vetor[l.quantidade] = container;
    l.quantidade++;
}

template<typename T, int MAX>
void inserir_inicio_lista_estatica(TListaEstatica<T,MAX> &l, T c) {
    if(l.quantidade >= MAX) {
        throw "List Overflow";
    }

    for(int i = l.quantidade; i>0; i--) {
        l.vetor[i] = l.vetor[i-1];
    }
    TElemento<T> container;
    container.dado = c;
    l.quantidade++;
}

template<typename T, int MAX>
void inserir_posicao_lista_estatica(TListaEstatica<T,MAX> &l, T c, int posicao) {
    if(l.quantidade >= MAX) {
        throw "List Overflow";
    }
    if(posicao < 0 || posicao > l.quantidade) {
        throw "Invalid Index";
    }
    for(int i = l.quantidade; i > posicao; i--) {
        l.vetor[i] = l.vetor[i-1];
    }

    TElemento<T> container;
    container.dado = c;
    l.vetor[posicao] = container;
    l.quantidade++;
}

template<typename T, int MAX>
void remover_fim_lista_estatica(TListaEstatica<T,MAX> &l) { }

template<typename T, int MAX>
void remover_inicio_lista_estatica(TListaEstatica<T,MAX> &l) { }

template<typename T, int MAX>
void remover_posicao_lista_estatica(TListaEstatica<T,MAX> &l) { }

#include <iostream>

template<typename T, int MAX>
void imprimir_lista(TListaEstatica<T,MAX> &l) {
    for(int i = 0; i < l.quantidade; i++) {
        std::cout << l.vetor[i].dado << std::endl;
    }
}

template<typename T, int MAX>
T obter_ultimo_dado(TListaEstatica<T,MAX> l) {
    return l.vetor[l.quantidade-1].dado;
}

template<typename T, int MAX>
T obter_posicao_dado(TListaEstatica<T,MAX> l, int posicao) {
    if(posicao < 0 || posicao >= l.quantidade) {
        throw "Invalid Index";
    }
    return l.vetor[l.quantidade-1].dado;
}

#include <algorithm>
#include <vector>
template<typename T, int MAX>
void trocar_posicoes_lista_estatica(TListaEstatica<T,MAX> &l, int pos1, int pos2) {

    TElemento<T> aux = l.vetor[pos1];
    l.vetor[pos1] = l.vetor[pos2];
    l.vetor[pos2] = aux;

}

#endif // LISTA_H
