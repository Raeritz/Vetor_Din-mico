#include <stdexcept>
#ifndef __ARRAY_LIST_IFRN__
#define __ARRAY_LIST_IFRN__


class array_list {
private:
    int* data;
    unsigned int size_, capacity_;
    int increase_strategy; // implementação do aumento de capacidade ;   1: 100   2: 1000   3: duplica
    void increase_capacity() {
        int* new_data;

        
        if (increase_strategy == 1) { //aumentama a capacidade
            new_data = new int[this->capacity_ + 100]; // Aumenta de 100 em 100
            this->capacity_ += 100;
        } else if (increase_strategy == 2) {
            new_data = new int[this->capacity_ + 1000]; // Aumenta de 1000 a 1000
            this->capacity_ += 1000;
        } else {
            this->capacity_ *= 2;
            new_data = new int[this->capacity_]; // Dobra a capacidade a cada expansão
        }

        
        for (unsigned int i = 0; i < this->size_; ++i) { // Copia os valores antigos para o novo array
            new_data[i] = this->data[i];
        }
        
        delete[] this->data;
        this->data = new_data;
    }
public:
    array_list(unsigned int initial_capacity) {
        data = new int[initial_capacity];
        this->size_ = 0;
        this->capacity_ = initial_capacity;
    }
    ~array_list() {
        delete[] data;
    }
    unsigned int size() {
        return this->size_;
    }
    unsigned int capacity() {
        return this->capacity_;
    }
    double percent_occupied() {
        return (static_cast<double>(this->size_) / this->capacity_) * 100.0;
    }
    bool insert_at(unsigned int index, int value) {
        if (index > this->size_)
            return false; // index errado

        if (this->size_ == this->capacity_)
            increase_capacity();

        for (unsigned int i = this->size_; i > index; --i) {
            this->data[i] = this->data[i - 1];
        }
        this->data[index] = value;
        this->size_++;
        return true;
    }
    bool remove_at(unsigned int index) {
        if (index >= this->size_)
            return false; // Não removeu
        for (unsigned i = index + 1; i < this->size_; ++i) {
            this->data[i - 1] = this->data[i];
        }
        this->size_--;
        return true; // Removeu
    }
    int get_at(unsigned int index) {
        if (index >= this->size_)
            throw std::out_of_range("index fora do range");
        return this->data[index];
    }
    void clear() {
        this->size_ = 0;
    }
    void push_back(int value) {
        if (this->size_ == this->capacity_)
            increase_capacity();
        this->data[size_++] = value;
    }
    void push_front(int value) {
        insert_at(0, value);
    }
    bool pop_back() {
        if (this->size_ == 0)
            return false;
        this->size_--;
        return true;
    }
    bool pop_front() {
        return remove_at(0);
    }
    int front(){
        if (this->size_ == 0)
            throw std::out_of_range("A lista está vazia");
        return this->data[0];
    }
    int back(){
        if (this->size_ == 0)
            throw std::out_of_range("A lista está vazia");
        return this->data[this->size_ - 1];
    }
    bool remove(int value) {
        int index = find(value);
        if (index == -1)
            return false;
        return remove_at(index);
    }
    int find(int value) {
        for (unsigned int i = 0; i < this->size_; ++i) {
            if (this->data[i] == value)
                return i;
        }
        return -1; // Não encontrado
    }
    int count(int value) {
        int count = 0;
        for (unsigned int i = 0; i < this->size_; ++i) {
            if (this->data[i] == value)
                count++;
        }
        return count;

    }
    int sum() {
        int total = 0;
        for (unsigned int i = 0; i < this->size_; ++i) {
            total += this->data[i];
        }
        return total;
    }
};


#endif // __ARRAY_LIST_IFRN__