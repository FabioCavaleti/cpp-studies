#include <iostream>
#include <vector>
#include <algorithm>
#include <execution>

int main()
{
    // if constexpr: Avaliação condicional em tempo de compilação
    constexpr bool condition = true;
    if constexpr (condition) {
        std::cout << "Condition is true" << std::endl;
    } else {
        std::cout << "Condition is false" << std::endl;
    }

    // structured bindings: Desestruturação de tuplas e estruturas
    auto [x, y] = std::make_pair(10, 20);
    std::cout << "x: " << x << ", y: " << y << std::endl;

    // std::optional, std::variant, std::any: Tipos de dados opcionais, variantes e genéricos que podem armazenar qualquer tipo

    // parallel alforithms: com std::execution
    std::vector<int> vec = {5,3,4,6,7,1, 8, 2, 9, 0};
    std::sort(std::execution::par, vec.begin(), vec.end());
    std::cout << "Sorted vector: ";
    for (const auto& elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // Filesystem library: Manipulação de arquivos e diretórios
    // std::filesystem::path path = "example.txt";
    // std::ofstream file(path);
    
    return 0;
}