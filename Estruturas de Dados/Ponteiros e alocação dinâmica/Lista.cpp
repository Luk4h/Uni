#include <iostream>

//Alocação dinâmica em lista.
int main() {

    struct TElemento {
        int dado;
        TElemento* prox;
    };

    struct TLista {
    
        TElemento* inicio;
    };

    TElemento* T1 = new TElemento;
    T1->dado = 10;
    T1->prox = NULL;
    TElemento* T2 = new TElemento;    
    T2 -> dado = 20;
    T2 -> prox = NULL;

    T1 -> prox = T2;

    return 0;


}