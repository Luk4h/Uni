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

    /*

    // Size of the struct assigned and pointer of struct assigned.
    Tdado a;
    std::cout<<"Size of a: "<< a) << std::endl;
    Tdado* b;
    std::cout<<"Size of a: "<< b) << std::endl;

    // Size of struct and struct with pointers.
    std::cout<<"Size of TDado: "<< Tdado) << std::endl;
    std::cout<<"Size of TDado_ptr: "<< Tdado_ptr) << std::endl;

    // Pointers always have 4 bytes of size.
    std::cout<<"Size of TDado*: "<< Tdado*) << std::endl;
    std::cout<<"Size of TDado_ptr*: "<< Tdado_ptr*) << std::endl;

    */


    int a = 10;
    std::cout<<"Size of a: "<< a <<" - Size of a&: "<< &a << std::endl;

    int* p_a = &a;
    std::cout<<"Size of p_a: "<< p_a <<" - Size of p_a&: "<< &p_a << std::endl;

    // Dynamic allocation.
    int* p_new_a = new int[5];
    std::cout<<"Size of p_new_a: "<< p_new_a <<" - Size of p_new_a&: "<< &p_new_a << std::endl;
   

   /*

    // User defined array size.
    int a = 0;
    std::cin>>a;

    int* b = new int[a];
    std::cout<<"Size of a: "<< a) << std::endl;

    */
    
   return 0;
}