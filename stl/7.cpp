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

// STL Algorithms - Non modifying algorithms: count, min, max, compare, linear search, attribute
// A maioria dos algoritmos retornam o primeiro elemento encontrado, mas existem alguns que retornam o último elemento encontrado

bool lessThan10(int x) { return x < 10; }

int main()
{

    std::vector<int> vec = {9, 60, 90, 8, 45, 87, 90, 69, 69, 55, 7};
    std::vector<int> vec2 = {9, 60, 70, 8, 45, 87};
    std::vector<int>::iterator it, it2;
    std::pair<std::vector<int>::iterator, std::vector<int>::iterator> pair_it;

    // C++11 lambda function
    bool num = count_if(vec.begin(), vec.end(), [](int x)
                        { return x < 10; });

    { // Count
        int n = std::count(vec.begin(), vec.end(), 69);
        int m = std::count_if(vec.begin(), vec.end(), lessThan10);
        std::cout << "Count of 69: " << n << std::endl;
        std::cout << "Count of < 10: " << m << std::endl;
    }

    { // Min and max
        it = max_element(vec.begin(), vec.end());
        std::cout << "Max element: " << *it << std::endl;
        it = max_element(vec.begin(), vec.end(), [](int x, int y)
                         { return (x % 10) < (y % 10); });
        std::cout << "Max element by last digit: " << *it << std::endl;
        it = min_element(vec.begin(), vec.end());
        std::cout << "Min element: " << *it << std::endl;
        pair_it = minmax_element(vec.begin(), vec.end(),
                                 [](int x, int y)
                                 { return (x % 10) < (y % 10); }); // Retorna o primeiro min encontrado e o ultimo max encontrado
        std::cout << "Min element by last digit: " << *pair_it.first << std::endl;
        std::cout << "Max element by last digit: " << *pair_it.second << std::endl;
    }

    { // Linear search (Use quando o container não é ordenado, pois o algoritmo de busca binária é mais eficiente quando o container é ordenado)
      // Retorna O primeiro elemento encontrado
        it = find(vec.begin(), vec.end(), 55);
        if (it != vec.end())
            std::cout << "Found: " << *it << std::endl;
        else
            std::cout << "Not found" << std::endl;
        it = find_if(vec.begin(), vec.end(), [](int x)
                     { return x < 80; });
        if (it != vec.end())
            std::cout << "Found: " << *it << std::endl;
        else
            std::cout << "Not found" << std::endl;
        it = find_if_not(vec.begin(), vec.end(), [](int x)
                         { return x < 80; });
        it = search_n(vec.begin(), vec.end(), 2, 69); // 2 elementos consecutivos iguais
        if (it != vec.end())
            std::cout << "Found: " << *it << std::endl;
        else
            std::cout << "Not found" << std::endl;

        // search subrange
        std::vector<int> sub = {45, 87, 90};
        it = search(vec.begin(), vec.end(), sub.begin(), sub.end()); // Retorna o primeiro subrange encontrado
        if (it != vec.end())
            std::cout << "Found subrange: " << *it << std::endl;
        else
            std::cout << "Not found subrange" << std::endl;

        it = find_end(vec.begin(), vec.end(), sub.begin(), sub.end()); // Retorna o último subrange encontrado
        if (it != vec.end())
            std::cout << "Found subrange: " << *it << std::endl;
        else
            std::cout << "Not found subrange" << std::endl;

        // Search any of
        std::vector<int> items = {87, 69};
        it = find_first_of(vec.begin(), vec.end(), items.begin(), items.end()); // Retorna o primeiro elemento encontrado que pertence ao vetor items
        if (it != vec.end())
            std::cout << "Found: " << *it << std::endl;
        else
            std::cout << "Not found" << std::endl;

        // Search adjacent
        it = adjacent_find(vec.begin(), vec.end()); // Retorna o primeiro elemento encontrado que é igual ao próximo

        it = adjacent_find(vec.begin(), vec.end(), [](int x, int y)
                           { return x == y * 4; }); // Retorna o primeiro elemento encontrado que é igual ao próximo multiplicado por 4
    }

    { // Comparing ranges
        if (equal(vec.begin(), vec.end(), vec2.begin()))
            std::cout << "Equal" << std::endl;
        else
            std::cout << "Not equal" << std::endl;

        if (is_permutation(vec.begin(), vec.end(), vec2.begin()))
            std::cout << "Permutation" << std::endl;
        else
            std::cout << "Not permutation" << std::endl;

        pair_it = mismatch(vec.begin(), vec.end(), vec2.begin()); // Encontra o primeiro elemento diferente entre os dois vetores

        lexicographical_compare(vec.begin(), vec.end(), vec2.begin(), vec2.end()); // comparacao um a um entre os dois vetores
    }

    {//Checking attributes
        is_sorted(vec.begin(), vec.end());

        it = is_sorted_until(vec.begin(), vec.end()); // Retorna o primeiro elemento que não está ordenado

        is_partitioned(vec.begin(), vec.end(), [](int x) {return x > 80;}); // Verifica se o vetor está particionado em dois grupos, um com elementos maiores que 80 e outro com elementos menores que 80

        is_heap(vec.begin(), vec.end());
        it = is_heap_until(vec.begin(), vec.end());

        all_of(vec.begin(), vec.end(), [](int x) { return x > 80;} ); // Verifica se todos os elementos satisfazem a condição

        any_of(vec.begin(), vec.end(), [](int x) { return x > 80;} ); // Verifica se algum elemento satisfaz a condição
        
        none_of(vec.begin(), vec.end(), [](int x) { return x > 80;} ); // Verifica se nenhum elemento satisfaz a condição


    }
    return 0;
}