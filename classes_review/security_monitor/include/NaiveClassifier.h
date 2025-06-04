#pragma once
#include "Classifier.h"

class NaiveClassifier : public Classifier
{
public:
    NaiveClassifier(std::string name);
    EventSeverity classify(const Event &event) const override;
    std::string getName() const override;
};