#include "Event.h"
#include "NaiveClassifier.h"
#include "EventStore.h"
#include "CryptoLogger.h"

#include <iostream>
#include <memory>
#include <vector>
#include <sstream>

std::string XOREncrypt(const std::string& input) // Simple mockup encript
{
    std::string output = input;
    std::string key = "super_secret_key";
    const size_t keyLen = key.size();
     
    for (size_t i = 0; i < output.size(); ++i)
    {
        output[i] ^= key[i % keyLen];
    }

    return output;
}

std::string printSeverity(EventSeverity sev)
{
    std::stringstream result;
    switch(sev)
    {
        case EventSeverity::BENIGN: result << "BENIGN\n"; break;
        case EventSeverity::SUSPICIOUS: result << "SUSPICIOUS\n"; break;
        case EventSeverity::MALICIOUS: result << "MALICIOUS\n"; break;
    }

    return result.str();
}

int main() 
{
    EventStore store;
    Event e1("192.168.1.10", EventType::LOGIN_FAIL, "Invalid password for admin");
    Event e2("10.0.0.2", EventType::LOGIN_SUCCESS, "Admin logged in");
    Event e3("10.0.0.2", EventType::FILE_ACCESS, "Access to secrets.txt");
    store.addEvent(e1);
    store.addEvent(std::move(e2));
    store.addEvent(e3);

    std::unique_ptr<Classifier> naive = std::make_unique<NaiveClassifier>(std::string("Naive"));

    CryptoLogger logger("secure_log.txt", XOREncrypt);

    if (!logger.isOpen())
    {
        std::cerr << "Falha ao abrir o log!";
        return 1;
    }

    
    

    store.forEach([&naive, &logger](const Event& e){
        std::stringstream eventLog;
        eventLog << e.formatToString() << " - " << naive->getName() << "classified event as: " << printSeverity(naive->classify(e));
        

        std::cout << eventLog.str() << std::endl;

        logger.logEvent(eventLog.str());
    });


}