#include <iostream>

// Normal struct with every type of data.
struct Tdado {
    int a;
    float b;
    double c;
    char d;
    bool e;
};

// Struct with every type of pointer.
struct Tdado_ptr {
    int* a;
    float* b;
    double* c;
    char* d;
    bool* e;
};

int main(){
    std::cout<<"Size of TDado: "<< sizeof(Tdado) << std::endl;
    std::cout<<"Size of TDado_ptr: "<< sizeof(Tdado_ptr) << std::endl;
    std::cout<<"Size of TDado*: "<< sizeof(Tdado*) << std::endl;
    std::cout<<"Size of TDado_ptr*: "<< sizeof(Tdado_ptr*) << std::endl;
}