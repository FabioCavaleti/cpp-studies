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
 * Strings parte 1
 * Obs: Capacidade é a quantidade de memória alocada para o objeto string, enquanto tamanho é a quantidade de caracteres armazenados no objeto string.
 * Quando o tamanho atinge a capacidade, a string é redimensionada para acomodar o novo tamanho.
 * A capacidade é sempre maior ou igual ao tamanho.
 */

int main()
{
    // constructors
    std::string s("Hello");
    std::string s2("Hello", 2); // Size
    std::string s3(s, 2); // Starting position
    std::string s4(s, 2, 2); // Starting position and size
    std::string s5(5, 'a'); // 
    std::string s6({'a', 'b', 'c', 'd', 'e'}); // Initializer list

    // size
    s.size();
    s.length();
    // Size and legnth are equivalent in std::string
    s.capacity(); // size of the allocated memory
    s.reserve(100); // Reserves memory for 100 characters, but does not change the size of the string

    s.shrink_to_fit(); // Reduces the capacity to fit the size of the string
    s.resize(3); // Resizes the string to the specified size, filling with null characters if the new size is larger than the current size
    s.clear(); // Clears the string, but does not change the capacity

    return 0;
}