# Revisão sobre classes

- Projeto: Sistema de monitoramento de eventos

## Anotações

- std::move() é uma função que converte um objeto em um rvalue e realiza a transferência de seus recursos para outro objeto, evitando cópias e deixando o código mais otimizado

- noexcept é uma especificação que indica que uma função não lança exceções. Com isso o compilador irá gerar o código de maneira mais eficiente, também facilita o entendimento do código para quem está lendo

- Construtor: Utilizar a lista de inicialização tem melhor performance que atribuição dentro do corpo
