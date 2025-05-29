#include <iostream>

// Modules: Substituição de cabeçalhos por módulos, melhorando a compilação e a modularidade
// import mymodule; - Precisa de uma flag específica de compilação para usar módulos, como -std=c++20 -fmodules-ts

// Concepts: Restrições de tipo para templates, melhorando a legibilidade e a segurança do código
// #include <concepts>

// template<typename T>
// concept Incrementable = requires(T x) { x++; };

// template<Incrementable T>
// T increment(T x) {
//     return x + 1;
// }


// Three-way comparison operator (<=>): Operador de comparação de três vias, simplificando a implementação de operadores de comparação
// #include <compare>

// struct Ponto {
//     int x, y;
//     auto operator<=>(const Ponto&) const = default;
// };

int main()
{
    // OBS: Meu compilador não suporta todos os recursos do C++20, então alguns recursos estão comentados.

    // coroutines: Suporte a corrotinas, permitindo programação assíncrona mais fácil e eficiente

    // ranges: Manipulação de sequências de dados de forma mais expressiva e eficiente
    // auto result = vec | std::views::filter([](int x){ return x > 0; });

    // consteval e constinit: Avaliação em tempo de compilação para funções e variáveis, melhorando a eficiência
    // consteval int quadrado(int x) { return x * x; }
    // constinit int valor = 10; // valor deve ser inicializado em tempo de compilação


    return 0;
}