#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>


struct Time {
    std::string nome;
    int pontos, vitorias, empates, derrotas;
};

std::vector<std::string> Split(std::string String, char separator) {
    std::string part;
    std::vector<std::string> Array;
    std::stringstream ss;
    ss.str(String);

    while ( std::getline ( ss, part, separator ))
    {
        Array.push_back(part);
    }

    return Array;
}

void heapify(Time arr[], int n, int i)
{
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2; 
    
    if (l < n && arr[l].pontos < arr[smallest].pontos)
        smallest = l;
    if (r < n && arr[r].pontos < arr[smallest].pontos)
        smallest = r;
    if (l < n && arr[l].pontos == arr[smallest].pontos && arr[l].vitorias < arr[smallest].vitorias)
        smallest = l;
    if (r < n && arr[r].pontos == arr[smallest].pontos && arr[r].vitorias < arr[smallest].vitorias)
        smallest = r;

    if (smallest != i) {
        std::swap(arr[i], arr[smallest]);

        heapify(arr, n, smallest);
    }
}

void heapSort(Time arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        std::swap(arr[0], arr[i]);

        heapify(arr, i, 0);
    }
}

void printArray(Time arr[], int n)
{
    for (int i = 0; i < n; ++i)
        std::cout << arr[i].nome << ": " << arr[i].pontos << " pts, " << arr[i].vitorias << " wins, " << arr[i].derrotas << " lost, " << arr[i].empates << " draws.\n";
}

int main()
{
    Time Times[1000];
    std::string line;
    std::ifstream myfile;
    myfile.open("Times.txt");
    int n = 0;
    if (myfile.is_open())
    {
        while ( std::getline (myfile, line) )
        {
            std::vector<std::string> Array = Split(line, ' ');
            Times[n].nome = Array[0];
            Times[n].pontos = std::stoi(Array[1]);
            Times[n].vitorias = std::stoi(Array[2]);
            Times[n].empates = std::stoi(Array[3]);
            Times[n].derrotas = std::stoi(Array[4]);
            n++;
        }
        myfile.close();
    }

    int size = sizeof(Times) / sizeof(Times[0]);

    heapSort(Times, size);

    std::cout << "HeapSorted array is \n";
    printArray(Times, size);
}

/*
Trabalho Ordenação de Times - 05/12/2021
Luiz Gustavo de Vergennes Marcondes.
Algoritmos e Programação II - Rodrigo Lyra
*/