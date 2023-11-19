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

#ifndef _APPLICATION_HPP_
#define _APPLICATION_HPP_

#include <array>

#include "Host.hpp"

class Application
{
public:
    static void Start();

    Application(const Application&) = delete;
    void operator= (const Application&) = delete;
private:
    Application();

    static Application& GetInstance();

    void xCreateTasks();

    static void xTaskHeartbeat(void* pvParameters);

    std::array<Host*, 2> m_Hosts;

    static Application m_Singleton;
};

#endif /* _APPLICATION_HPP_ */