#include <iostream>
#include <vector>
#include <algorithm>


int main()
{
    std::vector<int> vec;// Dinamicamente alocado na Heap, nao tem tamanho fixo.
    vec.push_back(4);
    vec.push_back(1);
    vec.push_back(8);

    std::vector<int>::iterator it1 = vec.begin();
    std::vector<int>::iterator it2 = vec.end(); // OBS: vec.end() aponta para o elemento apos o fim do vetor, portanto nao tente acessar seu valor pois ele e indefinido.

    for (std::vector<int>::iterator it = it1; it != it2; ++it)
    {
        std::cout << *it << " ";
    }

    std::sort(it1, it2);
    return 0;
}