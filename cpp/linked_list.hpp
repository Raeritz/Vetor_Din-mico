#ifndef __LINKED_LIST_IFRN__
#define __LINKED_LIST_IFRN__

class linked_list {
private:
    struct int_node {
        int value;
        int_node* next, * prev;
    };
    int_node* head, * tail;
    unsigned int size_;
public:
    linked_list() {
        this->head = nullptr;
        this->tail = nullptr;
        this->size_ = 0;
    }
    ~linked_list() {
        int_node* current = this->head;
        while (current != nullptr) {
            int_node* to_remove = current;
            current = current->next;
            delete to_remove;
        }
    }
    unsigned int size() {
        return this->size_;
    }
    unsigned int capacitty() {
        return size_; // considerando que lista ligada não tem limite fixo, logo só retornar size novamente
    }
    double percent_occupied() {
        return 100.0; //lista ligada não tem ocupação fixa, logo está sempre completa
    }
    bool insert_at(unsigned int index, int value) {
        if (index > this->size_) 
            return false;

        if (index == 0) {
            push_front(value);
            return true;
        }

        if (index == this->size_) {
            push_back(value);
            return true;
        }

        int_node* new_node = new int_node;
        new_node->value = value;
        int_node* current = this->head;
        
        for (unsigned int i = 0; i < index; ++i)
            current = current->next;

        new_node->prev = current->prev;
        new_node->next = current;
        current->prev->next = new_node;
        current->prev = new_node;

        ++this->size_;
        return true;
    }
    bool remove_at(unsigned int index) {
        if (index >= this->size_)
            return false; // Não removeu
        int_node* to_remove = this->head;
        for (unsigned int i = 0; i < index; ++i)
            to_remove = to_remove->next;
        if (to_remove->prev != nullptr)
            to_remove->prev->next = to_remove->next;
        if (to_remove->next != nullptr)
            to_remove->next->prev = to_remove->prev;
        delete to_remove;
        return true; // Removeu
    }
    int get_at(unsigned int index) {
        if (index >= this->size_)
            throw std::out_of_range("index fora do range");

        int_node* current = this->head;
        for (unsigned int i = 0; i < index; ++i)
            current = current->next;

        return current->value;
    }
    void clear() {
        int_node* current = this->head;
        while (current != nullptr) {
            int_node* to_remove = current;
            current = current->next;
            delete to_remove;
        }
        this->head = nullptr;
        this->tail = nullptr;
        this->size_ = 0;
    }
    void push_back(int value) {
        int_node* new_node = new int_node;
        new_node->value = value;
        new_node->next = nullptr;
        new_node->prev = this->tail;

        if (this->tail != nullptr)
            this->tail->next = new_node;
        this->tail = new_node;

        if (this->head == nullptr)
            this->head = new_node;

        ++this->size_;
    }
    void push_front(int value) {
        int_node* new_node = new int_node;
        new_node->value = value;
        new_node->next = this->head;
        new_node->prev = nullptr;
        if (this->head == nullptr)
            this->tail = new_node;
        else
            this->head->prev = new_node;
        this->head = new_node;
    }
    bool pop_back() {
        if (this->size_ == 0)
            return false;

        int_node* to_remove = this->tail;
        this->tail = to_remove->prev;
        
        if (this->tail != nullptr)
            this->tail->next = nullptr;
        else
            this->head = nullptr;

        delete to_remove;
        --this->size_;
        return true;
    }
    bool pop_front() {
        if (this->size_ == 0)
            return false;

        int_node* to_remove = this->head;
        this->head = to_remove->next;

        if (this->head != nullptr)
            this->head->prev = nullptr;
        else
            this->tail = nullptr;

        delete to_remove;
        --this->size_;
        return true;
    }
    int front() {
        if (this->head != nullptr)
            return this->head->value;
        throw std::out_of_range("A lista está vazia");
    }
    int back() {
        if (this->tail != nullptr)
            return this->tail->value;
        throw std::out_of_range("A lista está vazia");
    }
    bool remove(int value) {
        int_node* current = this->head;
        while (current != nullptr) {
            if (current->value == value) {
                if (current->prev != nullptr)
                    current->prev->next = current->next;
                else
                    this->head = current->next;

                if (current->next != nullptr)
                    current->next->prev = current->prev;
                else
                    this->tail = current->prev;

                delete current;
                --this->size_;
                return true;
            }
            current = current->next;
        }
        return false;
    }
    int find(int value) {
        int_node* current = this->head;
        int index = 0;
        while (current != nullptr) {
            if (current->value == value)
                return index;
            current = current->next;
            ++index;
        }
        return -1;  // Não encontrado
    }
    int count(int value) {
        int count = 0;
        int_node* current = this->head;
        while (current != nullptr) {
            if (current->value == value)
                ++count;
            current = current->next;
        }
        return count;
    }
    int sum() {
        int sum = 0;
        int_node* current = this->head;
        while (current != nullptr) {
            sum += current->value;
            current = current->next;
        }
        return sum;
    }
};

#endif // __LINKED_LIST_IFRN__