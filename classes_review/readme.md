# Revisão sobre classes

- Projeto: Sistema de monitoramento de eventos

## Anotações

- std::move() é uma função que converte um objeto em um rvalue e realiza a transferência de seus recursos para outro objeto, evitando cópias e deixando o código mais otimizado

- noexcept é uma especificação que indica que uma função não lança exceções. Com isso o compilador irá gerar o código de maneira mais eficiente, também facilita o entendimento do código para quem está lendo

- Construtor: Utilizar a lista de inicialização tem melhor performance que atribuição dentro do corpo


- RAII: Técnica de gerenciamento de recursos em que a alocação e liberação dos recursos estão ligadas ao tempo de vida de um objeto. Geralmente realizamos a aquisição do recurso no construtor e a liberação no destrutor, garantindo que nenhum recurso fique vazando, mesmo se ocorrer uma exceção.


## Project tree

security_monitor/
├── CMakeLists.txt                # Configuração do build
├── README.md                     # Explicação do projeto
├── include/                      # Headers (interface das classes)
│   ├── Event.h
│   ├── Classifier.h
│   ├── NaiveClassifier.h
│   ├── MLClassifier.h
│   ├── CryptoLogger.h
│   ├── EventStore.h
│   └── Utils.h                   # Funções auxiliares (ex: enums → string)
├── src/                          # Implementações (cpps)
│   ├── Event.cpp
│   ├── NaiveClassifier.cpp
│   ├── MLClassifier.cpp
│   ├── CryptoLogger.cpp
│   ├── EventStore.cpp
│   └── main.cpp
├── assets/                       # Arquivos simulados (ex: logs)
│   └── sample_log.txt
├── tests/                        # Testes unitários (opcional)
│   └── test_classifier.cpp
└── build/     