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

/*
 * Unordered Containers: São estruturas de dados que se assemelham a uma hash table: existe uma chave que passa por uma função hash, a qual a mapeia para seu valor respectivo na tabela hash.
 * Propriedades:
 * 1. Tempo de inserção e busca constante O(1), desde que não haja problema de hash collision (Problema em que varios elementos estejam no mesmo bucket)
 * 2. Unordered set/multiset -> Elementos não podem ser alterados; Unordered map/multimap -> Chaves não podem ser alteradas, mas seus valores sim.
 */

/*
 * Unordered set: Semelhante ao set mas não se preocupa sem manter uma estrutura ordenada
 *
 *
 *
 */

/*
 * Associative Array: Podem ser criados utilizando unordered map ou map
 * 1. Busca: unordered_map O(1) ou O(n) dependendo de collisions, map O(log(n))
 * 2. Não pode utilizar multimap nem unordered_multimap pois eles não tem o operador []
 *
 *
 */

/*
 * Container Adaptor:
 * - São containers que oferecem uma interface mais restritiva sobre containers subjacentes, resumindo eles adaptam um container já existente para um novo uso
 * - stack: LIFO, push(), pop(), top()
 * - queue: FIFO, push(), pop(), front(), back()
 * - priority queue: first item -> greatest priority, push(), pop(), top()
 */

 /*
 * Array based containers: vector, deque -> Invalida ponteiros, pois os elementos são armazenados em memória contínua. Se voce inserir um elemento no inicio de um vector, o ponteiro que apontava anteriormente para a segunda posição terá comportamento indefinido
 * Node base containers: list + associative containers + unordered containers -> Já nesse caso cada elemento tem seu próprio espaço dedicado na memória e qualquer tipo de operação não irá alterar a referencia dos ponteiros
 * 
 */

void foo(const std::unordered_map<char, std::string> &m)
{
    // std::cout << m['S'] << std::endl; - Errado
    auto itr = m.find('S');
    if (itr != m.end())
    {
        std::cout << itr->second << std::endl;
    }
}

int main()
{
    {
        std::cout << "--- Unordered Set ---" << std::endl;
        std::unordered_set<std::string> myset = {"red", "green", "blue"};

        std::unordered_set<std::string>::const_iterator itr = myset.find("green"); // O(1)
        if (itr != myset.end())
        {
            std::cout << *itr << std::endl;
        }
        myset.insert("yellow"); // O(1)

        std::vector<std::string> vec = {"purple", "pink"};
        myset.insert(vec.begin(), vec.end());

        // Hash table specific
        std::cout << "load_factor = " << myset.load_factor() << std::endl;
        std::string x = "red";
        std::cout << x << " is in bucket #" << myset.bucket(x) << std::endl;
        std::cout << "Total bucket #" << myset.bucket_count() << std::endl;
    }

    {
        std::cout << "--- Unordered Map ---" << std::endl;
        std::unordered_map<char, std::string> day = {{'S', "Sunday"}, {'M', "Monday"}};

        std::cout << day['S'] << std::endl;
        std::cout << day.at('S') << std::endl;

        day['W'] = "Wednesday";
        day.insert(std::make_pair('F', "Friday"));

        day.insert(std::make_pair('M', "MONDAY")); // Função insert não pode ser usada para atualizar o valor de uma determinada chave
        std::cout << day['M'] << std::endl;
        day['M'] = "MONDAY";
        std::cout << day['M'] << std::endl;
        // OBS: O operador [] para um unordered map é considerado uma operação de escrita... Então se voce utilizar day['M'] e o tipo do unordered map for const, então ele irá dar erro de compilação!!
        foo(day);
    }
}