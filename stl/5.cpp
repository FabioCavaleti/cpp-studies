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
#include <forward_list>

#include <iostream>

// Iterators and algorithms
/*
 * Iteradores:
 * 1. Iteradores de acesso randomico -> Vector, Deque, Array
 * - Podem acessar posições aleatórias do container, já que eles armazenam os dados sequencialmente na memória.
 * 2. Iteradores bidirecionais -> list, set/multiset, map/multimap
 * - Precisam percorrer os elementos sequencialmente com incremento / decremento para chegar no elemento que se quer chegar
 * 3. Iteradores Forward: Forward list
 * - Só conseguem ir para o próximo elemento, não é possível voltar para o anterior
 * 4. Unordered iterators: Unordered containers
 * - Garante que irá fornecer PELO MENOS iteradores forward.
 * 5. Input iterators
 * - Iteradores que permitem acessar seu valor com int x = *itr;
 * - Só pode se mover para frente (forward iterator)
 * 6. Output iterators
 * - Iteradores que permitem receber novas atribuições de valores *itr = 100;
 * - Só pode se mover para frente (forward iterator)
 *
 * -> Todo container possuem dois iteradores:
 * - std::container<type>::iterator // Read and write
 * - std::container<type>::const_iterator // Read only
 */

/*
 * Iterator Adaptor (Predefines Iterator)
 * - Um iterador mais poderoso, que geralmente modifica o comportamente de algum dos iteradores padrão
 * - insert iterator, stream iterator, reverse iterator, move iterator (c++ 11)
 *
 *
 */

/*
 * Algoritmos: São em sua maioria loops. Existem vários algoritmos diferentes, mas sempre que voce estiver usando loop no seu codigo pode ser que haja um algoritmo da stl que te ajude
 *
 *
 *
 */

bool isOdd(int i)
{
    return i % 2;
}

void f(int i)
{
    std::cout << i << " ";
}

int main()
{
    { // Random access iterators
        std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
        std::vector<int>::iterator itr;
        std::vector<int>::iterator itr2;
        itr = vec.begin();
        itr2 = vec.begin();
        itr = itr + 5;
        itr -= 4;
        if (itr > itr2)
        {
            --itr;
            ++itr2;
        }

        // OBS: ++it é mais rápido que it++ pois não precisa armazenar o valor anterior de retorno.
    }

    { // Bidirectional iterators
        std::list<int> list = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
        std::list<int>::iterator it = list.begin();
        ++it;
        --it;
        // it + 3; // ERRO
    }

    {
        std::forward_list<int> flist = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
        std::forward_list<int>::iterator it = flist.begin();
        ++it;
    }

    { // Constant iterator
        std::set<int> set = {1, 2, 3, 4, 5, 6, 7, 8};
        std::set<int>::iterator it;
        std::set<int>::const_iterator cit;

        for (cit = set.begin(); cit != set.end(); ++cit)
        {
            std::cout << *cit << " ";
            // *cit = 3; // ERRO, const_iterator permite apenas leitura
        }
        std::cout << std::endl;

        for_each(set.cbegin(), set.cend(), f); // C++ 11
        std::cout << std::endl;

        it = set.begin();
        cit = --set.end();
        advance(it, 2);               // Avança o iterator em 2 posições, it += 2
        int dist = distance(it, cit); // retorna a distancia entre 2 iteradores
        std::cout << "Distance: " << dist << std::endl;
    }

    { // Iterator Adapter

        { // Insert Iterator:
            std::vector<int> vec1 = {1, 2};
            std::vector<int> vec2 = {4, 5, 6, 7, 8, 9, 0};
            std::vector<int>::iterator it = find(vec2.begin(), vec2.end(), 8);
            std::insert_iterator<std::vector<int>> i_it(vec2, it);
            copy(vec1.begin(), vec1.end(), // Source
                 i_it);                    // Destination

            for (auto it = vec2.begin(); it != vec2.end(); ++it)
            {
                std::cout << *it << " ";
            }
            std::cout << std::endl;

            // Other insert iterators: back_insert_iterator, front_insert_iterator.
        }

        // { // Stream Iterator
        //     std::vector<std::string> vec = {{"Hogwarts"}, {"is"}, {"awesome"}};
        //     copy(std::istream_iterator<std::string>(std::cin), std::istream_iterator<std::string>(), std::back_inserter(vec));

        //     copy(vec.begin(), vec.end(), std::ostream_iterator<std::string>(std::cout, " "));

        //     copy(std::istream_iterator<std::string>(std::cin), std::istream_iterator<std::string>(), std::ostream_iterator<std::string>(std::cout, " "));
        // }

        { // Reverse Iterator
            std::vector<int> vec = {4, 5, 6, 7, 8};
            std::reverse_iterator<std::vector<int>::iterator> rit;
            for (rit = vec.rbegin(); rit != vec.rend(); ++rit)
            {
                std::cout << *rit << " ";
            }
            std::cout << std::endl;
        }
    }

    { // Algorithms
        std::vector<int> vec = {4, 2, 5, 1, 3, 9};
        std::vector<int>::iterator it = min_element(vec.begin(), vec.end());

        // 1: Algoritmos sempre pocessam ranges no sentido [begin, end), ou seja, a posição end passada não é acessada
        sort(vec.begin(), vec.end());
        for (auto val : vec)
        {
            std::cout << val << " ";
        }
        std::cout << std::endl;

        reverse(vec.begin(), vec.end());
        for (auto val : vec)
            std::cout << val << " ";
        std::cout << std::endl;

        // 2
        it = vec.end() - 2;
        std::vector<int> vec2(3);
        copy(it, vec.end(), // Source
             vec2.begin()); // Destination
        // A função copy copia os elemento de [source.begin(), source.end()) para o destination a partir de destination.begin(),
        // ela não cria novos elementos no destination, portanto se o container tiver um tamanho menor que o intervalo do source passado
        // para a função, então o comportamento dessa função será indefinido.

        // 3
        std::vector<int> vec3;
        copy(it, vec.end(), std::back_inserter(vec3)); // Corrige o problema anterior, faz com que a função insira ao inves de sobrescrever
        // Observe que esse código é ineficiente
        // É muito melhor usar:
        vec3.insert(vec3.end(), it, vec.end()); // Eficiente e seguro.

        // 4: Algoritmo com função
        it = find_if(vec.begin(), vec.end(), isOdd);
        std::cout << *it << std::endl;

        // 5: Algoritmos podem funcionar com Array C++ nativo.
        int arr[4] = {6, 3, 7, 4};
        std::sort(arr, arr+4);
    }

    return 0;
}