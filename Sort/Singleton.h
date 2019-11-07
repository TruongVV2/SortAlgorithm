#include <iostream>
#include <string>
#include <mutex>

class Singleton
{
    private:
        Singleton(std::string name)
        {
            m_name = name;
        }
    private:
        std::string m_name;
        //static Singleton* ptrInstance;
        static std::mutex m_mutex;
    public:
        static Singleton* getInstance(std::string name);
        std::string getName();
        void TurnOnBackgroundMusic();
        void TurnOffBackgroundMusic();

};