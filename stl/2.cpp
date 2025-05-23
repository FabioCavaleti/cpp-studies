#include <vector>
#include <deque>
#include <list>
#include <set>           // set and multiset
#include <map>           //map and multimap
#include <unordered_set> // Unordered set/multiset
#include <unordered_map> // unordered map/multimap
#include <iterator>
#include <algorithm>
#include <numeric> // numeric algorithms
#include <functional>

#include <iostream>

// Sequence Containers
/*
 * Vector -> Array dinamico com tamanho variável
 * Propriedades:
 * 1. Rapido para remover e inserir elementos no fim: O(1)
 * 2. Lento para remover e inserir elementos no começo / meio: O(n)
 * 3. Lento para busca: O(n)
 */

/*
 * Deque -> Semelhante ao vector mas permite adicionar e remover elementos tanto no começo quanto no final.
 * Propriedades:
 * 1. Rapida inserção e remoção no começo e no fim: O(1)
 * 2. Lento para inserção e remoção no meio: O(n)
 * 3. Lento para busca: O(n)
 */

/*
 * List -> Cada elemento tem dois ponteiros, um que aponta para o próximo elemento e outro que aponta para o elemento anterior da lista.
 * Propriedades:
 * 1. Rápida inserção e remoção em qualquer lugar da lista: O(1)
 * 2. Busca lenta: O(n) // OBS: essa busca é bem mais lenta que o vetor e a deque, pois o vetor armazena os elementos em uma sequencia continua na memória,
 * enquanto que a lista armazena cada elemento em um espaço dedicado na memória. Os elementos estarem sequencialmente armazenado na memória facilita a utilização da memória cache, a qual consegue acessar os elementos sequenciais muito mais rapidamente.
 * 3. Não possui o operador [] para acesso randomico, ou seja tem que percorrer elemento a elemento do inicio ou fim até chegar no elemento que se quer acessar.
 * 4. Método splice: Permite adicionar elementos de uma lista em outra lista com complexidade O(1)
 */

/*
 * Foward List -> Semelhante a lista, porém cada elemento tem apenas um ponteiro que aponta para o próximo elemento da lista.
 * 
 */

 /*
  * Array -> É um container que representa o tipo built - in do array de C++
  * Propriedades:
  * 1. Funciona exatamente igual um array normal, mas permite a utilziação de iteradores e algoritmos da stl
  * 2. O tamanho do array faz parte de seu tipo e não pode ser alterado. Logo array<int, 3> e array<int, 4> são de tipos diferentes
  */
int main()
{
    {
        std::cout << "--- Vector ---" << std::endl;
        std::vector<int> vec;
        vec.push_back(4);
        vec.push_back(1);
        vec.push_back(8);

        std::cout << vec[2] << " ";          // Não checa o range do vector
        std::cout << vec.at(2) << std::endl; // Lança a exceçao range_error se estiver out of range

        for (int i; i < vec.size(); ++i)
        {
            std::cout << vec[i] << " ";
        }
        std::cout << std::endl;

        // Usar iterators é mais rápido que acessar utilizando v[i]...
        for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl;

        for (auto it : vec) // C++11
        {
            std::cout << it << " ";
        }
        std::cout << std::endl;

        int *p = &vec[0]; // Permite acessar o vetor com um ponteiro

        // Funções comuns para todos os containers
        vec.empty();
        vec.size();
        vec.clear();
        std::vector<int> vec2(vec); // Inicializa a partir de outro container
        vec2 = {1, 2, 3};
        vec2.swap(vec); // Troca o conteudo dos dois containers

        std::cout << "vec content: ";
        for (auto it : vec)
        {
            std::cout << it << " ";
        }
        std::cout << std::endl;

        std::cout << "vec2 content: ";
        for (std::vector<int>::iterator it = vec2.begin(); it != vec2.end(); ++it)
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
    // OBS: essas funções são todas muito eficientes.

    {
        std::cout << "--- Deque ---" << std::endl;
        std::deque<int> deq = {4, 6, 7};
        deq.push_front(2);
        deq.push_back(3);
    }

    {

        std::cout << "--- List ---" << std::endl;
        std::list<int> mylist = {5, 2, 9}; 
        mylist.push_back(6);
        mylist.push_front(4);

        std::list<int>::iterator it = std::find(mylist.begin(), mylist.end(), 2);
        mylist.insert(it, 8);
        ++it;
        mylist.erase(it);

        //mylist1.splice(it, mylist2, it_a, it_b); 
    }

    {
        std::cout << "--- Array (Container) ---" << std::endl;
        std::array<int, 3> a = {3, 4, 5};
        a.begin();
        a.end();
        a.size();
        // a.swap();
    }
    
    
    return 0;
}