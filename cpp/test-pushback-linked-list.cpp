#include <iostream>
#include <chrono>
#include "linked_list.hpp"

int main() {
    int n;
    std::cin >> n;  // inserir elementos

    linked_list l1;
    auto beg = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < n; ++i) {
        int x;
        std::cin >> x;  // ler para inserir
        l1.push_front(x);
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = end - beg;

    if (l1.size() != n) {
        std::cerr << "[ERROR] Verifique o método push_front!\n";
        exit(1);
    }

    std::cerr << "[INFO] Tempo para " << n << " inserções no início: " 
              << elapsed.count() << " ns" << std::endl;
    return 0;
}
