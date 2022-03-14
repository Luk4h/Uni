#ifndef CARTA_H
#define CARTA_H

#include <iostream>
#include "lista.h"
#include "time.h"
using namespace std;

struct TCarta {
    int naipe;
    int valor;
};


const string NAIPES[]={"Espada", "Copas", "Ouros", "Paus"};

ostream& operator <<(ostream &os, TCarta c) {
    os << "Carta{ naipe: " << NAIPES[c.naipe] << ", valor: "
       << c.valor << "}";
    return os;
}

TListaEstatica<TCarta,52> criar_baralho() {
    TListaEstatica<TCarta,52> baralho;
    inicializar_lista_estatica(baralho);

    for(int i = 0; i < 52; i++) {
        TCarta carta;
        carta.naipe = i / 13;
        carta.valor = (i % 13) + 1;
        inserir_fim_lista_estatica(baralho, carta);
    }
    return baralho;
}

void embaralhar(TListaEstatica<TCarta,52> &baralho) {
    srand(time(NULL));

    for(int i = 0; i < 26; i++) {
        int posicao1 = rand() % 52;
        int posicao2 = rand() % 52;
        trocar_posicoes_lista_estatica(baralho,posicao1,posicao2);
    }
}

#endif // CARTA_H
