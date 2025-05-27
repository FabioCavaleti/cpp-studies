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
#include <random>

#include <iostream>

// Sorting algorithm - Requer iteradores de acesso aleatório como vector, deque, array, string, etc.

bool lsb_less(int x, int y)
{
    return (x % 10) < (y % 10);
}

bool lessThan10(int i)
{
    return i < 10;
}

int main()
{
    std::vector<int> vec = {9, 1, 10, 2, 45, 3, 90, 4, 9, 5, 8};

    sort(vec.begin(), vec.end());
    sort(vec.begin(), vec.end(), lsb_less);

    // As vezes não precisamos ordenar todo o vetor, mas apenas uma parte dele.
    partial_sort(vec.begin(), vec.begin() + 5, vec.end(), std::greater<int>()); // Ordena os primeiros 5 elementos de vec

    partial_sort(vec.begin(), vec.begin() + 5, vec.end()); // Ordena os primeiros 5 elementos de vec em ordem crescente

    nth_element(vec.begin(), vec.begin() +5, vec.end(), std::greater<int>()); // Garante que os 5 primeiros elementos de vec sejam os maiores, mas não os ordena

    partition(vec.begin(), vec.end(), lessThan10); // Particiona os elementos de vec em dois grupos: os menores que 10 e os maiores ou iguais a 10

    stable_partition(vec.begin(), vec.end(), lessThan10); // Particiona os elementos de vec em dois grupos, mas mantém a ordem relativa dos elementos

    // Heap Algorithms: Heap -> Maior elemento sempre está no topo da pilha (acesso em tempo constante O(1))
    // Adicionar e remover elementos tem complexidade O(log n)

    make_heap(vec.begin(), vec.end()); 

    pop_heap(vec.begin(), vec.end()); // Move o maior elemento para o final do vetor, mas não o remove

    vec.pop_back(); // Remove o último elemento do vetor, que é o maior elemento após a chamada de pop_heap

    push_heap(vec.begin(), vec.end()); // Adiciona um novo elemento ao heap, mantendo a propriedade do heap
    vec.push_back(100); // Adiciona um novo elemento ao final do vetor
    push_heap(vec.begin(), vec.end()); // Adiciona o novo elemento ao heap, mantendo a propriedade do heap

    // Heap sorting
    sort_heap(vec.begin(), vec.end()); // Ordena os elementos de vec2 em ordem crescente, usando o heap. Observe que o vetor deve estar em ordem de heap antes de chamar esta função.





    

    return 0;
}