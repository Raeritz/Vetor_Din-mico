#include <iostream>
#include "array_list.hpp"

int main() {
    array_list list(3);  // Capacidade sendo duplicada

    
    for (int i = 0; i < 1000; ++i) {
        list.push_back(i); // adiciona no final do vetor
    }

    
    std::cout << "Capacidade: " << list.capacity() << std::endl; // capacidade final

    
    std::cout << "posição 0: " << list.get_at(0) << std::endl; // Verificando alguns elementos inseridos
    std::cout << "posição 999: " << list.get_at(999) << std::endl; // Verificando alguns elementos inseridos

    return 0;
}
