#pragma once
#include <string>
#include <chrono>

// Tipos de eventos a serem monitorados

enum class EventType // Enum class 
{
    LOGIN_FAIL,
    LOGIN_SUCCESS,
    FILE_ACCESS,
    PORT_SCAN,
    UNKNOWN
};

// classe que representa um evento individual

class Event
{
private:                                              // Define atributos privados da classe
    std::string sourceIP_;                            // Geralmente utiliza - se "_" no final do nome de variáveis privadas
    std::chrono::system_clock::time_point timestamp_; // data/hora do evento
    EventType type_;
    std::string rawData_;
public:
    Event(std::string sourceIp, EventType type, std::string rawData);

    const std::string& getSourceIP() const noexcept;
    std::chrono::system_clock::time_point getTimestamp() const noexcept;
    EventType getType() const noexcept;
    const std::string& getRawData() const noexcept;

    std::string formatToString() const;
};