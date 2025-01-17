Array_list:

Comando para compilar os testes:

push_front:
g++ -Wall -o test-pushfront-array-list test-pushfront-array-list-01.cpp
./test-pushfront-array-list

push_back:
g++ -Wall -o test-pushback-array-list test-pushback-array-list-01.cpp
./test-pushback-array-list

remove_at:
g++ -Wall -o test-removeat-array-list test-removeat-array-list-01.cpp
./test-removeat-array-list
	
pop_front:
g++ -Wall -o test-popfront-array-list test-popfront-array-list-01.cpp
./test-popfront-array-list

pop_back:
g++ -Wall -o test-popback-array-list test-popback-array-list-01.cpp
./test-popback-array-list

size and percent:
g++ -Wall -o test-size-percent-array-list test-size-percent-array-list.cpp
./test-size-percent-array-list

Big_O dos testes:

push_front: O(n);

push_back: O(1);

remove_at: O(n);

pop_front: O(n);

pop_back: O(1);

size and percent: O(1)



Implementação de variavél e métodos:

implementação da variável "increase_strategy" para realizer os aumento de capacidade. Sendo controladas por parâmetros que determinam qual deve ser o aumento de capacidade, se "increase_strategy" for igual a 1, a capacidade aumentará de 100 em 100 ou se "increase_strategy" for igual a 2, a capacidade aumentará de 1000 em 1000 ou se "increase_strategy" for igual a 1, a capacidade duplicará. 

double percent_occupied()
retorna a porcentagem da capacidade usada atualmente na lista.

bool insert_at(unsigned int index, int value)
Insere um valor na posição específicada por index, sendo index quem especifica a posição e value o valor a ser colocado caso o indice esteja fora da lista, retorna false e caso a lista esteja cheia a capacidade é aumentada.

int get_at(usigned int index)
Implementado verificação para saber se o index é válido ou não. Se for válido, o valor do elemento é retornado.

void clear()
size_ é redefinido para 0, porém capacity_ não é alterada, para que ainda seja possível inserir novos elementos sem precisar alocar novo espaço na memória.

void push_front(int value)
Insere value no início da lista, chamando o método insert_at(0, value) que insere no index 0 da lista.

bool pop_back()
Se a lista estiver vazia retorna false, caso não esteja, remove o último valor da lista.

bool pop_front()
Chama o método remove_at(0) para remover valor que está na posição 0.

int front()
Se a lista estiver vazia retorna uma exceção, caso a lista não esteja vazia ele retorna o primeiro valor da lista.

int back()
Se a lista estiver vazia retorna uma exceção, caso a lista não esteja vazia retornará o último valor da lista.

bool remove(int value)
Remove o valor específio de value, usando find(value) para encontrar o index e chamando remove_at(index) para removê-lo.

int find(int value)
Retorna o índice de value, caso o valor não seja encontrado o método retornará -1.

int count(int value)
Conta e retorna a quantidade total de vezes que o número presente em value apareçe na lista.

int sum()
Retorna a soma de todos os valores da lista.



/////////////////////////////

Linked_list:

Comando para compilar os testes:

push_front:
g++ -Wall -o test-pushfront-linked-list-01 test-pushfront-linked-list-01.cpp
./test-pushfront-linked-list-01 < tests/push/e1.txt
	
push_back:
g++ -Wall -o test-pushback-linked-list-01 test-pushback-linked-list-01.cpp
./test-pushback-linked-list-01 < tests/push/e2.txt
	
remove_at:
g++ -Wall -o test-removeat-linked-list-01 test-removeat-linked-list-01.cpp
./test-removeat-linked-list-01 < tests/remove/e1.txt

pop_front:
g++ -Wall -o test-popfront-linked-list-01 test-popfront-linked-list-01.cpp
./test-removefront-linked-list-01 < tests/remove/e2.txt	
	
pop_back:
g++ -Wall -o test-popback-linked-list-01 test-popback-linked-list-01.cpp
./test-popback-linked-list-01 < tests/remove/e3.txt

Big_O dos testes:

push_front: O(1);

push_back: O(1);

remove_at: O(n);

pop_front: O(1);

pop_back: O(1);



Implementação de métodos:

unsigned int size()
Retorna a variável size_, que é responsável por retornar os números de elementos na lista.

unsigned int capacity()
Retorna o mesmo valor da variável size_, pois a lista ligada não possui um tamanho fixo não havendo limitação de capacidade.

percent_occupied()
Retorna a porcentagem ocupada da lista, porém como a lista não possui limite máximo o método sempre retornará 100%.

bool insert_art(unsigned int index, int value)
Insere um novo nó em posição especificada, tendo condições como se o index for 0 o método chamará push_front ou caso o index igual o tamanho da lista o método chamará push_back e caso contrário das duas condições anteriores ele irar inserir o nó ajustando os ponteiros dos nós presentes na lista.

int get_at(unsigned int index)
Retorna o valor do nó na posição especificada, caso o index for falso ele retornará exceção.

void clear()
o método percorre os nós da lista e libera a memória de todos eles.

void push_back(int value)
Adicionará um nó no final da lista, caso a lista esteja vazia antes do nó ser adicionado ele será tanto head quanto tail.

bool pop_back()
Remove o último nó da lista, ajustando o ponteiro tail para o penúltimo nó.

bool pop_front()
Remove o primerio nó da lista, ajustando o ponteiro head para o próximo nó.

int front()
Retorna o valor do primeiro nó, que no caso é o ponteiro head, porém caso a lista esteja vazia será usado uma exceção que diz que a lista se encotra vazia.

int back()
Retorna o valor do último nó, que no caso é o ponteiro tail, porém caso a lista esteja vazia será usado uma exceção que diz que a lista se encontra vazia.

bool remove(int value)
Remove o primeiro nó que o value indica e fornece, assim o método ajustará os ponterios e deletará o nó especificado por value.

int find(int value)
Procura a posição do nó que contém o valor de value e o retorna. Caso ele percorra a lista toda e não encontre o valor será retornado -1.

int count(int value)
Conta e retorna a quantidade total de vezes que o número presente em value apareçe na lista.

int sum()
Retorna a soma de todos os valores presentes na lista.
