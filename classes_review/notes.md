# Notes

- `std::move()` é uma função que converte um objeto em um rvalue e realiza a transferência de seus recursos para outro objeto, evitando cópias e deixando o código mais otimizado

    - Utilizar a estrutura `Event&& var` permite a utilização de `std::move`, o operador `&&` é utilizado para indicar uma referência de um rvalue.

- noexcept é uma especificação que indica que uma função não lança exceções. Com isso o compilador irá gerar o código de maneira mais eficiente, também facilita o entendimento do código para quem está lendo

- Construtor: Utilizar a lista de inicialização tem melhor performance que atribuição dentro do corpo


- RAII: Técnica de gerenciamento de recursos em que a alocação e liberação dos recursos estão ligadas ao tempo de vida de um objeto. Geralmente realizamos a aquisição do recurso no construtor e a liberação no destrutor, garantindo que nenhum recurso fique vazando, mesmo se ocorrer uma exceção.

- Functional é uma parte da biblioteca padrao que fornece utilidades relacionadas a funções e objetos funcionais (functors).

- O uso de `const` no final de métodos indica que que o método não modifica o estado do objeto. Isso significa que o método não pode modificar nenhum atributo do objeto, exceto atributos marcados como `mutable`. É uma boa prática marcar métodos que não alteram o objeto como const.

- A sintaxe do `std::function` pode ser um pouco confusa a princípio. o `std::function` é um objeto que pode armazenar qualquer função, lambda ou functor.  durante a declaração:
`void forEach(const std::function<void(const Event&)>& func const` tudo que está entre `<>` está definindo a variável `func` que será (uma função) passada para `std::function`