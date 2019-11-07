#include "Singleton.h"

// Singleton* Singleton::ptrInstance = nullptr;

Singleton* Singleton::getInstance(std::string name)
{
    // m_mutex.lock();
    // if (ptrInstance == nullptr) {
    //     ptrInstance = new Singleton(name);
    // }
    // m_mutex.unlock();
    static Singleton ptrInstance = Singleton(name);
    return &ptrInstance;
}

std::string Singleton::getName()
{
    return m_name;
}

void Singleton::TurnOnBackgroundMusic()
{
    // turn on background music
    std::cout << "TurnOnBackgroundMusic is called" << std::endl;
}
void Singleton::TurnOffBackgroundMusic()
{
    // turn off background music
    std::cout << "TurnOffBackgroundMusic is called" << std::endl;
}