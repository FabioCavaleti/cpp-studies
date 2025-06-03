#include "Event.h"
#include "NaiveClassifier.h"

#include <iostream>
#include <memory>
#include <vector>

void printSeverity(EventSeverity sev)
{
    switch(sev)
    {
        case EventSeverity::BENIGN: std::cout << "BENIGN\n"; break;
        case EventSeverity::SUSPICIOUS: std::cout << "SUSPICIOUS\n"; break;
        case EventSeverity::MALICIOUS: std::cout << "MALICIOUS\n"; break;
    }
}

int main() 
{
    Event e1("192.168.1.10", EventType::LOGIN_FAIL, "Invalid password for admin");
    Event e2("10.0.0.2", EventType::LOGIN_SUCCESS, "Admin logged in");
    Event e3("10.0.0.2", EventType::FILE_ACCESS, "Access to secrets.txt");
    std::vector<Event> event_list = {e1, e2, e3};
    std::unique_ptr<Classifier> naive = std::make_unique<NaiveClassifier>(std::string("Naive"));

    for (auto e: event_list)
    {
        std::cout << e.formatToString() << " - " << naive->getName() << "classified event as: ";
        printSeverity(naive->classify(e));

    }


}