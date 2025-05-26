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

/*
 * Sorted Data Algorithms - Requerem que os dados já estejam ordenados: busca binaria, merge, set operations, etc.
 */

int main()
{
    // OBS: os containers devem estar ordenados nesses exemplos abaixo, a menos que explicitamente é dito o contrário

    { // Binary Search
        std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        bool found = binary_search(vec.begin(), vec.end(), 5); // Busca binária para encontrar o elemento 5 em vec

        std::vector<int> s = {1, 2, 3, 15};
        found = includes(vec.begin(), vec.end(), s.begin(), s.end()); // Verifica se todos os elementos de s estão em vec

        // search position
        auto it = lower_bound(vec.begin(), vec.end(), 5); // Retorna um iterador para o primeiro elemento que não é menor que 5

        it = upper_bound(vec.begin(), vec.end(), 5); // Retorna um iterador para o primeiro elemento que é maior que 5

        auto pair_of_it = equal_range(vec.begin(), vec.end(), 5); // Retorna um par de iteradores que delimitam o intervalo de elementos iguais a 5
    }

    { // Merge
        std::vector<int> vec = {8, 9, 9, 10};
        std::vector<int> vec2 = {7, 9, 10};
        std::vector<int> vec_out(vec.size() + vec2.size());
        merge(vec.begin(), vec.end(), vec2.begin(), vec2.end(), vec_out.begin()); // Nenhum elemento é removido, nem mesmo as duplicatas. Os elementos são ordenados e inseridos em vec_out.

        vec = {1, 2, 3, 4, 1, 2, 3, 4, 5};                      // O vetor está ordenado em duas partes, mas não é um vetor ordenado completo.
        inplace_merge(vec.begin(), vec.begin() + 5, vec.end()); // Mescla as duas partes ordenadas do vetor em um único vetor ordenado. A primeira parte é de 0 a 4 e a segunda parte é de 5 a 8.
    }

    { // Set operations
        std::vector<int> vec = {8, 9, 9, 10};
        std::vector<int> vec2 = {7, 9, 10};
        std::vector<int> vec_out(5);

        std::set_union(vec.begin(), vec.end(),
                       vec2.begin(), vec2.end(),
                       vec_out.begin()); // União dos dois vetores, sem duplicatas. Os elementos são ordenados e inseridos em vec_out.
        
        for (const auto& elem : vec_out) {
            std::cout << elem << " "; // Imprime os elementos da união
        }
        std::cout << std::endl;

        set_intersection(vec.begin(), vec.end(),
                          vec2.begin(), vec2.end(),
                          vec_out.begin()); // Interseção dos dois vetores, ou seja, os elementos que estão em ambos os vetores. Os elementos são ordenados e inseridos em vec_out.
        for (const auto& elem : vec_out) { 
            std::cout << elem << " "; // Imprime os elementos da interseção
        }
        std::cout << std::endl;

        set_difference(vec.begin(), vec.end(),
                       vec2.begin(), vec2.end(),
                       vec_out.begin()); // Diferença dos dois vetores, ou seja, os elementos que estão em vec, mas não em vec2. Os elementos são ordenados e inseridos em vec_out.

        set_symmetric_difference(vec.begin(), vec.end(),
                                   vec2.begin(), vec2.end(),
                                   vec_out.begin()); // Diferença simétrica dos dois vetores, ou seja, os elementos que estão em um dos vetores, mas não em ambos. Os elementos são ordenados e inseridos em vec_out.
    }

    {// Numeric algorithms - Estao declarado em <numeric> e nao em <algorithm>: accumulate, inner product, partial sum, adjacent difference
        std::vector<int> vec = {1, 2, 3, 4, 5};

        int sum = accumulate(vec.begin(), vec.end(), 0); // Soma todos os elementos de vec, começando com 0
        int mult = accumulate(vec.begin(), vec.end(), 1, std::multiplies<int>()); // Multiplica todos os elementos de vec, começando com 1

        int product = inner_product(vec.begin(), vec.end(), vec.begin(), 0); // Produto interno de vec com ele mesmo, começando com 0

        partial_sum(vec.begin(), vec.end(), vec.begin()); // Calcula a soma parcial dos elementos de vec, ou seja, cada elemento é a soma dos elementos anteriores

        adjacent_difference(vec.begin(), vec.end(), vec.begin()); // Calcula a diferença entre cada elemento e o anterior, ou seja, cada elemento é a diferença entre o elemento atual e o anterior


    }

    return 0;
}