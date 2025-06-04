#pragma once
#include "Event.h"
#include <fstream>
#include <functional>
#include <memory>
#include <string>

class CryptoLogger
{
private:
    std::ofstream file_;
    std::function<std::string(const std::string &)> encryptFunc_;

public:
    explicit CryptoLogger(const std::string &filepath,
                          std::function<std::string(const std::string &)> encryptFunc_);
    // void logEvent(const Event& event);
    void logEvent(const std::string& plaintext);
    bool isOpen() const noexcept;
};