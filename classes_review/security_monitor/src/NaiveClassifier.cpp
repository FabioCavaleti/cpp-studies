#include "NaiveClassifier.h"

NaiveClassifier::NaiveClassifier(std::string name): Classifier(std::move(name)) {}

std::string NaiveClassifier::getName() const
{
    return name_;
}

EventSeverity NaiveClassifier::classify(const Event& event) const
{
    switch(event.getType())
    {
        case EventType::PORT_SCAN:
            return EventSeverity::MALICIOUS;
        case EventType::LOGIN_FAIL:
            return EventSeverity::SUSPICIOUS;
        case EventType::FILE_ACCESS:
            return EventSeverity::BENIGN;
        case EventType::LOGIN_SUCCESS:
            return EventSeverity::BENIGN;
        default:
            return EventSeverity::MALICIOUS;
            
    }
}