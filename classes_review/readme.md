# Revisão sobre classes

- Projeto: Sistema de monitoramento de eventos de segurança da informação em C++ moderno

## O que foi estudado

- **Fundamentos de classes em C++**: encapsulamento, construtores, destrutores, inicialização de membros, const correctness, enum class, RAII, uso de std::move, noexcept, getters/setters.
- **Herança e polimorfismo**: uso de classes abstratas (Classifier), métodos virtuais puros, e implementação de classificadores concretos (NaiveClassifier).
- **Gerenciamento de recursos**: smart pointers (`std::unique_ptr`), uso correto de referências e cópias, boas práticas de ownership.
- **Manipulação de datas e strings**: uso de `std::chrono` para timestamp, `std::string` para dados textuais.
- **Criptografia e logging**: logger que aplica criptografia XOR e codificação Base64 antes de salvar eventos em arquivo.
- **Utilização de funções utilitárias**: separação de funções auxiliares (ex: enums para string, base64) em arquivos utilitários.
- **Integração com Python**: script `decoder.py` para decodificar e ler os logs criptografados.
- **Boas práticas de projeto**: organização modular (include/src), uso de CMake, versionamento com Git, `.gitignore` bem configurado.

## Estrutura do projeto

security_monitor/
├── CMakeLists.txt                # Configuração do build
├── include/                      # Headers (interface das classes)
│   ├── Event.h
│   ├── Classifier.h
│   ├── NaiveClassifier.h
│   ├── CryptoLogger.h
│   ├── EventStore.h
│   └── utils.h                   # Funções auxiliares (ex: enums → string, base64)
├── src/                          # Implementações (cpps)
│   ├── Event.cpp
│   ├── NaiveClassifier.cpp
│   ├── CryptoLogger.cpp
│   ├── EventStorte.cpp
│   ├── main.cpp
│   └── utils.cpp
└── build/                        # Artefatos de build (ignorado pelo git)

## Exemplos de conceitos aplicados

- Uso de smart pointers para gerenciamento automático de memória
- Métodos const e noexcept para segurança e performance
- Enum class para tipos seguros
- Funções lambda e std::function para flexibilidade
- Logger criptografado e decodificador em Python

---

Esse projeto serve como referência prática e didática para revisão de classes, recursos modernos do C++ e boas práticas de organização de código.