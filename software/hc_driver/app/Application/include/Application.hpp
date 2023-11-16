/**
 * \file Application.hpp
 * 
 * \brief Main application class
 * 
 * This class represents the apllication
 * 
 * \author Ramon de Araujo Borba <ramonborba97@gmail.com>
 * 
 * \version 0.1
 * 
 * \date 15-11-2023
 */

#define HEARTBEAT_LED_PIN       2
#define HEARTBEAT_PERIOD_MS     500

class Application
{
public:
    static void start();

    static void Heartbeat();

    Application(const Application&) = delete;
    void operator= (const Application&) = delete;
private:
    Application() = default;

    static Application& GetInstance();

    void createTasks();

    static Application m_Singleton;
};