#include <iostream>
#include "array_list.hpp"

int main() {
    array_list list(3);  // Duplicação de capacidade

    
    for (int i = 0; i < 500; ++i) {
        list.push_back(i); // inserir de elementos
    }

    
    std::cout << "Tamanho da lista: " << list.size() << std::endl;  // tamanho ; Esperado: 500
    
    std::cout << "Percentual ocupado: " << list.percent_occupied() << "%" << std::endl; // percentual de ocupação

    return 0;
}