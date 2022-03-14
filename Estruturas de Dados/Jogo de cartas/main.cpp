#include <iostream>
#include "lista.h"
#include "carta.h"
using namespace std;

struct TJogador {
    std::string nome;
//      TListaEstaticaCartas mao;
    float carteira;
};


ostream& operator <<(ostream &os, TJogador c) {
    os << "Jogador{ nome: " << c.nome << " carteira: " << c.carteira << "}";
    return os;
}

int main() {

        TListaEstatica<TCarta,52> baralho_mesa;
        baralho_mesa = criar_baralho();
        embaralhar(baralho_mesa);

        imprimir_lista(baralho_mesa);
        return 0;
}
