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

// stream part 4: Manipulators

int main()
{
    std::cout << "Hello" << std::endl;// endl -> '\n' + flush => endl é uma função que manipula os streams, ou seja, é um manipulador de fluxo que executa operações de formatação e controle de fluxo. Ele insere uma nova linha no fluxo de saída e força o buffer a ser descarregado (flush), garantindo que todos os dados sejam escritos imediatamente no dispositivo de saída (geralmente o console).
    std::cout << std::ends; // ends é um manipulador de fluxo que insere um caractere nulo ('\0') no fluxo de saída, indicando o final de uma string. Isso é útil quando se deseja garantir que a string seja tratada como uma string C-style, terminada em nulo.
    std::cout << std::flush; // flush é um manipulador de fluxo que força o buffer de saída a ser descarregado, garantindo que todos os dados sejam escritos imediatamente no dispositivo de saída. Isso é útil quando se deseja garantir que os dados sejam exibidos imediatamente, sem esperar pelo buffer ser preenchido ou pelo programa terminar.
    std::cin >> std::ws; // ws é um manipulador de fluxo que ignora os espaços em branco (como espaços, tabulações e quebras de linha) no fluxo de entrada. Ele é usado para limpar o buffer de entrada antes de ler dados, garantindo que não haja espaços em branco indesejados antes dos dados lidos.
    
    return 0;
}