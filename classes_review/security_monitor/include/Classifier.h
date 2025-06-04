#pragma once
#include "Event.h"

enum class EventSeverity
{
    BENIGN,
    SUSPICIOUS,
    MALICIOUS
};

// Interface abstrata para classificadores, não pode ser instanciada diretamente
class Classifier
{
private:
protected:
    std::string name_;
    Classifier(std::string name) : name_(name) {}

public:
    virtual ~Classifier() = default;

    virtual std::string getName() const = 0;
    virtual EventSeverity classify(const Event &event) const = 0;
};