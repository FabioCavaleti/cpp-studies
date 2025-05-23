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

// Associative containers - Containers que são impolementados com uma estrutura semelhante a uma árvore binária
//  1. Sempre ordenado, critério default é <
// 2. Métodos push_front e push_back não fazem sentido nesse tipo de estrutura
//  3. Sempre que um elemento é inserido a estrutura se reordena, inserindo o elemento no local adequado
/*
 * Set -> Estrutura que não permite valores repetidos
 * Multiset -> Semelhante ao set, mas permite valores duplicados
 * Obs: Set e Multiset são read-only, ou seja, seus valores não podem ser modificados, apenas inseridos, acessados e deletados.
 *  Propriedades:
 * 1. Busca: O(log(n))
 * 2. Acessar todos os elementos é muito lento...
 * 3. O iterador é do tipo const e não pode ser modificado
 */

/*
 * Map e Multimap -> Armazenam um par chave-valor
 * Propriedades:
 * 1. A ordenação acontece pela chave e não pelo valor
 * 
 *
 */

int main()
{
    {
        std::cout << "--- Set ---" << std::endl;
        std::set<int> myset;
        myset.insert(3);
        myset.insert(1);
        myset.insert(7);

        std::set<int>::iterator it;
        it = myset.find(7); // Containers de sequencia não possuem o a funçao find

        std::pair<std::set<int>::iterator, bool> ret;
        ret = myset.insert(3);   // Método insert retorna um std::pair com o iterador e com um booleado indicando se a inserção aconteceu com sucesso
        if (ret.second == false) // Retorn falso quando o elemento já existe no set
            it = ret.first;

        myset.insert(it, 9); // É possível passar um iterador no método insert, ele serve como uma "dica", uma referência de onde o elemento deve ser inserido, aumentando a performance da inserção para até O(1). Observe que nós não conseguimos escolher onde o elemento será inserido, apenas adicionar uma referencia para que o método encontre o local correto mais rapidamente.

        myset.erase(it);
        myset.erase(7); // Podemos remover elementos tanto utilizando o iterador quanto utilizando seu valor literal.
    }

    {
        std::cout << "--- Map ---" << std::endl;
        std::map<char, int> mymap;
        mymap.insert(std::pair<char, int>('a', 100));
        mymap.insert(std::make_pair('z', 200));//std::make_pair infere os tipos. Lembrando que um template de classe nao consegue inferir os tipos das entradas, mas um template de funcao consegue.

        std::map<char, int>::iterator it = mymap.begin();
        mymap.insert(it, std::pair<char, int>('b', 300));

        it = mymap.find('z'); // O(log(n))

        for (it=mymap.begin(); it != mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << std::endl;

        
    }



    return 0;
}