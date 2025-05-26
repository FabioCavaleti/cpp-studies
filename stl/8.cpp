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

// STL Algorithms - Value changing algorithms - Changes the element values: copy, move, transform, swap, fill, replace, remove.

int main()
{
    { // Copy

        std::vector<int> vec = {9, 60, 70, 8, 45, 87, 90};
        std::vector<int> vec2 = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        std::vector<int>::iterator it, it2;
        std::pair<std::vector<int>::iterator, std::vector<int>::iterator> pair_of_it;
        copy(vec.begin(), vec.end(), vec2.begin()); // Copia os elementos de vec para vec2
        copy_if(vec.begin(), vec.end(), vec2.begin(), [](int x)
                { return x > 80; });

        copy_n(vec.begin(), 4, vec2.begin()); // Copia os primeiros 4 elementos de vec para vec2

        copy_backward(vec.begin(), vec.end(), vec2.end()); // Copia os elementos de vec para vec2, mas inverte a ordem
    }

    { // Move
        std::vector<std::string> vec = {"Hogwarts", "Hufflepuff", "Gryffindor", "Ravenclaw", "Slytherin"};
        std::vector<std::string> vec2(vec.size());

        move(vec.begin(), vec.end(), vec2.begin()); // Se a semantica de movimento for suportada, move os elementos de vec para vec2, caso contrário copia os elementos

        move_backward(vec.begin(), vec.end(), vec2.end());
    }

    { // Transform
        std::vector<int> vec = {9, 60, 70, 8, 45, 87, 90};
        std::vector<int> vec2 = {9, 60, 70, 8, 45, 87, 90};
        std::vector<int> vec3 = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

        transform(vec.begin(), vec.end(), vec3.begin(), [](int x)
                  { return x - 1; }); // Aplica a função lambda em cada elemento de vec e armazena o resultado em vec3

        transform(vec.begin(), vec.end(), // src 1
                  vec2.begin(),           // src 2
                  vec3.begin(),           // dest
                  [](int x, int y)
                  { return x + y; }); // Aplica a função lambda em cada elemento de vec e vec2 e armazena o resultado em vec3
    }

    { // Swap
        std::vector<int> vec = {9, 60, 70, 8, 45, 87, 90};
        std::vector<int> vec2 = {9, 60, 70, 8, 45, 87, 90};

        swap_ranges(vec.begin(), vec.end(), vec2.begin()); // Troca os elementos de vec com os elementos de vec2
    }

    { // Fill
        std::vector<int> vec = {0, 0, 0, 0, 0};
        std::vector<int> vec2 = {0, 0, 0, 0, 0};

        fill(vec.begin(), vec.end(), 8);
        fill_n(vec.begin(), 3, 9); // Preenche os primeiros 3 elementos de vec com 9
        generate(vec.begin(), vec.end(), []()
                 { return rand() % 100; }); // Preenche os elementos de vec com valores aleatórios entre 0 e 99

        generate_n(vec.begin(), 3, rand);

        // Replace
        replace(vec.begin(), vec.end(), 8, 9); // Substitui todos os elementos iguais a 8 por 9

        replace_if(vec.begin(), vec.end(), [](int x)
                   { return x > 80; }, 9);

        replace_copy(vec.begin(), vec.end(), vec.begin(), 9, 8); // Substitui todos os elementos iguais a 9 por 8 e copia o resultado para o mesmo vetor

        // remove
        remove(vec.begin(), vec.end(), 9); // Remove todos os elementos iguais a 9, mas não altera o tamanho do vetor
        remove_if(vec.begin(), vec.end(), [](int x)
                  { return x > 80; });                        // Remove todos os elementos maiores que 80, mas não altera o tamanho do vetor
        remove_copy(vec.begin(), vec.end(), vec2.begin(), 9); // Remove todos os elementos iguais a 9 e copia o resultado para o mesmo vetor

        unique(vec.begin(), vec.end()); // Remove os elementos duplicados, mas não altera o tamanho do vetor
        unique(vec.begin(), vec.end(), std::less<int>());

        unique_copy(vec.begin(), vec.end(), vec2.begin()); // Remove os elementos duplicados e copia o resultado para vec2

        { // Order changing containers
            std::vector<int> vec = {9, 60, 70, 8, 45, 87, 90};
            std::vector<int> vec = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

            {                                            // Reverse
                reverse(vec.begin() + 1, vec.end() - 1); // Inverte a ordem dos elementos entre o segundo e o penúltimo elemento

                reverse_copy(vec.begin() + 1, vec.end() - 1, vec2.begin());
            }

            {// rotate
                rotate(vec.begin(), vec.begin() + 3, vec.end()); // Rotaciona os elementos de vec, movendo os primeiros 3 elementos para o final do vetor

                rotate_copy(vec.begin(), vec.begin() + 3, vec.end(), vec2.begin()); // Rotaciona os elementos de vec, movendo os primeiros 3 elementos para o final do vetor e copia o resultado para vec2
            }

            {// Permute
                next_permutation(vec.begin(), vec.end()); // Gera a próxima permutação dos elementos de vec
                prev_permutation(vec.begin(), vec.end()); // Gera a permutação anterior dos elementos de vec
            }

            {// Shuffle - Rearranges the elements in a random order
                random_shuffle(vec.begin(), vec.end());
                random_shuffle(vec.begin(), vec.end(), rand);

                
                shuffle(vec.begin(), vec.end(), std::default_random_engine()); // C++11
                
                }
        }
    }

    return 0;
}