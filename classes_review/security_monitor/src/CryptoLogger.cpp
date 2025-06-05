#include "CryptoLogger.h"
#include "utils.h"



CryptoLogger::CryptoLogger(const std::string &filepath,
                           std::function<std::string(const std::string &)> encryptFunc)
    : file_(filepath, std::ios::app), encryptFunc_(std::move(encryptFunc)) {}

// void CryptoLogger::logEvent(const Event& event)
// {
//     if (file_.is_open())
//     {
//         std::string plaintext = event.formatToString();
//         std::string ciphertext = encryptFunc_(plaintext);
//         file_  << ciphertext << "\n";
//     }
// }

void CryptoLogger::logEvent(const std::string& plaintext)
{
    if (file_.is_open())
    {
        std::string ciphertext = encryptFunc_(plaintext);
        std::string enconded_ciphertext = base64_encode(ciphertext);
        file_ << enconded_ciphertext << "\n";
    }
}

bool CryptoLogger::isOpen() const noexcept
{
    return file_.is_open();
}