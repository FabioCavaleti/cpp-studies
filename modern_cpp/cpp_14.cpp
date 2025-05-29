#include <iostream>
#include <memory>

int main()
{
    //Generalized lambda capture -> capturar variáveis por valor utilizando move
    // make_unique -> Forma segura e eficiente de criar ponteiros únicos
    // return type deduction -> Dedução automática do tipo de retorno de funções


    auto ptr = std::make_unique<int>(42);

    auto lambda = [ptr = std::move(ptr)]() mutable {
        std::cout << "Value: " << *ptr << std::endl;
    };


    
    return 0;
}