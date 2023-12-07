/**
 * \file App.hpp
 * 
 * \brief Application class responsible for implementing the application logic
 * 
 * \author Ramon de Araujo Borba <ramonborba97@gmail.com>
 * 
 * \version 0.1
 * 
 * \date 20-11-2023
 */

#pragma once

#include "SerialPort.hpp"

class Application
{
public:
    static void Start();
private:
    Application();

    static void SerialMonitor();

    static void SendCommand(int axis, int val);

    static Application m_Host;
    SerialPort m_Serial;
};