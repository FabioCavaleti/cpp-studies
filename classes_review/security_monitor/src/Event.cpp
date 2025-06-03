#include "Event.h" // Header
#include <sstream> // stringstream
#include <iomanip> // setfill, setw

// RAII -> Variáveis serão inicializadas no construtor e liberadas automaticamente
Event::Event(std::string sourceIP, EventType type, std::string rawData) : sourceIP_(std::move(sourceIP)),
                                                                          timestamp_(std::chrono::system_clock::now()),
                                                                          type_(type), rawData_(std::move(rawData)) {}

const std::string &Event::getSourceIP() const noexcept { return sourceIP_; }

std::chrono::system_clock::time_point Event::getTimestamp() const noexcept { return timestamp_; }

EventType Event::getType() const noexcept { return type_; }

const std::string &Event::getRawData() const noexcept {return rawData_; }

// Função utilitária para converter EventType em string legível
static const char* eventTypeToString(EventType type) {
    switch(type) {
        case EventType::LOGIN_FAIL: return "LOGIN_FAIL";
        case EventType::LOGIN_SUCCESS: return "LOGIN_SUCCESS";
        case EventType::FILE_ACCESS: return "FILE_ACCESS";
        case EventType::PORT_SCAN: return "PORT_SCAN";
        default: return "UNKNOWN";
    }
}

//RAII -> a stringstream é inicializada no momento da chamada do método e liberada automaticamente ao final do escopo
std::string Event::formatToString() const
{
    std::ostringstream oss;
    std::time_t time = std::chrono::system_clock::to_time_t(timestamp_);
    oss << "[" << std::put_time(std::localtime(&time), "%F %T") << "] ";
    oss << "From: " << sourceIP_ << " Type: " << eventTypeToString(type_);
    oss << " Data: " << rawData_;

    return oss.str();
}