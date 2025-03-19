#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>


using std::string;
using std::hex;
using std::setw;
using std::setfill;
using std::cerr;
using std::endl;
using std::cin;
using std::cout;
using std::getline;
using std::ostringstream;
using std::stoi;
using std::size_t;

std::string toHex(const std::string& data) 
{
    std::ostringstream oss;
    for (unsigned char c : data) 
    {
        oss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(c);
    }
    return oss.str();
}

std::string xorEncryptDecrypt(const std::string& text, const std::string& key) 
{
    std::string result = text;

    for (size_t i {}; i < text.size(); ++i) 
    {
        result[i] = text[i] ^ key[i % key.size()];
    }

    return result;
}
std::string fromHex(const std::string& hex) 
{
    if (hex.size() % 2 != 0) 
    {
        std::cerr << "Некорректная длина шестнадцатеричной строки!" << std::endl;
        return "";
    }

    std::string result;
    for (size_t i = 0; i < hex.size(); i += 2) 
    {
        std::string byteString = hex.substr(i, 2);
        unsigned char byte = static_cast<unsigned char>(std::stoi(byteString, nullptr, 16));
        result.push_back(byte);
    }
    return result;
}

int main() 
{
    int choice;
    std::string text, encryptedText, key;

    std::cout << "Выберите режим:\n";
    std::cout << "1. Зашифровать текст\n";
    std::cout << "2. Расшифровать текст\n";
    std::cout << "Введите номер режима (1 или 2): ";
    std::cin >> choice;
    std::cin.ignore(); 

    if (choice != 1 && choice != 2) 
    {
        std::cerr << "Неверный выбор режима!" << std::endl;
        return 1;
    }

    std::cout << "Введите ключ: ";
    std::getline(std::cin, key);

    if (key.empty()) 
    {
        std::cerr << "Ключ не может быть пустым!" << std::endl;
        return 1;
    }

    if (choice == 1) 
    {
        std::cout << "Введите текст для шифрования: ";
        std::getline(std::cin, text);

        std::string encryptedText = xorEncryptDecrypt(text, key);
        encryptedText = toHex(encryptedText);
        std::cout << "Зашифрованный текст (в шестнадцатеричном формате): " << encryptedText << std::endl;
    }
    else
    {
        std::cout << "Введите зашифрованный текст (в шестнадцатеричном формате): ";
        std::getline(std::cin, encryptedText);

        encryptedText = fromHex(encryptedText); 
        if (!encryptedText.empty()) 
        {
            std::string decryptedText = xorEncryptDecrypt(encryptedText, key);
            std::cout << "Расшифрованный текст: " << decryptedText << std::endl;
        }
    }

    return 0;
}
