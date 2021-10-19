#include <iostream>

struct arma {
    float danoMax;
    float danoMin;
};

struct inimigo {
    char nome[16];
    int vida;
    arma arma;
};

struct jogador {
    char nome[16];
    int vida;
    arma arma;
    int posX;
    int posY;
};

struct bloco {
    bool bloqueado;
    bool temInimigo;
    inimigo* inimigo;
};

struct mapa {
    int A;
    int L;
    bloco* blocos;
};

struct fase {
    char nome[16];
    mapa mapa;
    int numInimigos;
    inimigo inimigos[];
};
 
//TODO: FIX AND ASK FOR HELP.
mapa criarMapa( int altura, int largura ) {
    mapa *novoMapa;
    novoMapa = new mapa;
    novoMapa->A = altura;
    novoMapa->L = largura;

    bloco* blocos;
    blocos = new bloco[altura*largura];

    for (int n = 0; n < altura * largura; n++) {
        srand(time(NULL));
        int r = rand() % 100;
        std::cout << (r) << std::endl;
        if (r < 20) {
            blocos[n].bloqueado = true;
        }
    }
    novoMapa->blocos = blocos;
    return *novoMapa;
}












int main()
{
    fase teste;
    teste.mapa = criarMapa(2, 2);
    for (int i = 0; i < 4; i++)
    {
        std::cout << teste.mapa.blocos[i].bloqueado << std::endl;
    }
}