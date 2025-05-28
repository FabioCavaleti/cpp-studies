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
#include <fstream>

#include <iostream>

// Stream part 1
// cout é um objeto global da classe ostream, que é usado para enviar dados para a saída padrão (geralmente o console).
// ostream é um typedef basic_ostream<char>
// O operador << é uma função membro da classe ostream que é sobrecarregado para permitir a inserção de diferentes tipos de dados no fluxo de saída.
// <<: ostream& ostream::operator<< (string v);
// o std::endl pode ser entendido de maneira superficial como se fosse um '\n' seguido de um flush do buffer de saída, mas na verdade é uma função que retorna um manipulador de fluxo que executa essas operações.

// O que é stream? stream é uma interface serial de IO para dispositivos externos. Isso significa que a leitura e escrita de dados é feita de forma sequencial, byte a byte, ou caractere a caractere.

int main()
{
    std::cout << "Hello" << std::endl;

    std::string s = "Hogwarts is awesome !!";
    {
        std::ofstream of("file.txt"); // cria um stream de saída para o arquivo "file.txt". Caso o arquivo não exista, ele será criado. Se já existir, o conteúdo será sobrescrito.

        if (of.is_open())
        {
            of << s << std::endl; // escreve a string s no arquivo e adiciona uma nova linha.
            of.close();
        }
    } // OBS: Podemos inserir o ofstream dentro de um escopo e quando ele sair do escopo será automaticamente destruido... É uma técnica RAII

    //IO Operation:
    // Formatar os dados <---> Comunicar com o dispositivo externo
    // Principio da engenharia de software: Low Coupling -> ter um módulo que não depende de outro módulo, ou seja, o módulo de formatação não deve depender do módulo de comunicação com o dispositivo externo.
    return 0;
}