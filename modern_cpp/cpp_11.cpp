#include <iostream>
#include <vector>
#include <memory>

int main()
{
    // auto: Dedução automática de tipo
    auto x = 42;

    // ranged-based for loop
    std::vector v = {1, 2,3, 4,5, 6, 7, 8};
    for (const auto &x : v)
        std::cout << x << " ";
    std::cout << std::endl;

    // Smart pointers - Gerenciadores inteligentes, liberam memória automaticamente
    std::unique_ptr<int> p1(new int(10)); // Ponteiro único, não pode ser copiado
    std::shared_ptr<int> pShared(new int(20)); // Ponteiro compartilhado, pode ser copiado
    std::weak_ptr<int> pWeak(pShared); // Ponteiro fraco, não impede a liberação de memória

    // Lambda expressions
    auto sum = [](int a, int b) {return a + b;};

    std::cout << sum(10, 20) << std::endl;

    // nullptr: Ponteiro nulo
    int* p2 = nullptr;

    // constexpr: Constantes em tempo de compilação
    constexpr int constValue = 100;

    // move semantics
    std::vector<int> vec1 = {1, 2, 3};
    std::vector<int> vec2 = std::move(vec1); // Move vec1 to vec2
    std::cout << "vec2 contents: ";
    for (const auto& elem : vec2) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // Multithreading
    // std::thread, std::mutex, std::lock_guard, std::asyn, std::future
    

    
    return 0;   
}