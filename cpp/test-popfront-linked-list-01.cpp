#include <iostream>
#include <chrono>
#include "linked_list.hpp"

int main() {
    int n;
    std::cin >> n;  // Número de elementos a remover

    linked_list l1;
    for (int i = 0; i < n; ++i) {
        l1.push_back(i);  // Adição no final
    }

    auto beg = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < n; ++i) {
        l1.pop_front();  // Remoção do início
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = end - beg;

    std::cerr << "[INFO] Tempo para remoções no início: " 
              << elapsed.count() << " ns" << std::endl;

    return 0;
}
