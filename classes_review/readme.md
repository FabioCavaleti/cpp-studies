# Revisão sobre classes

- Projeto: Sistema de monitoramento de eventos


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