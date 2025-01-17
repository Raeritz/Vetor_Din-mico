#include <iostream>
#include "array_list.hpp"

int main() {
    array_list list(3);  // Capacidade sendo duplicada

    // Inserção de elementos
    for (int i = 0; i < 1000; ++i) {
        list.push_back(i);
    }

    
    for (int i = 0; i < 500; ++i) { // Removendo elementos do início
        list.pop_front();  // Remover sempre o primeiro
    }

    
    std::cout << "Tamanho após remoções: " << list.size() << std::endl; // Verificando quantidade de elementos restantes

    return 0;
}