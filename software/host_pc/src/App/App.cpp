/**
 * \file App.cpp
 * 
 * \brief Application class implementataion
 * 
 * \author Ramon de Araujo Borba <ramonborba97@gmail.com>
 * 
 * \version 0.1
 * 
 * \date 20-11-2023
 */

#include <iostream>
#include <limits>
#include <format>
#include <string>
#include <cstdint>
#include <thread>
#include "unistd.h"
#include "sys/ioctl.h"

#include "App.hpp"
#include "SerialPort.hpp"
#include "Logger.hpp"

Application Application::m_Host;

Application::Application() : m_Serial { "/dev/ttyUSB1" } {

}

static void WaitKeyPress() {
    std::cout << "\nPress Enter to continue.\n";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::cin.get();
}

void Application::SerialMonitor(){
    int i, nbytes;
    Logger& log = Logger::GetInstance();

    LogData data_buf (Event(0, 0));

    // std::cout << "Starting monitoring task.\n";
    while(true)
    {
        nbytes = m_Host.m_Serial.Read(&data_buf, sizeof(data_buf));
        if (nbytes > 0) {
            std::cout << "\n" <<  nbytes << "bytes received\n";
            std::cout << data_buf << "\n";
            log.Add(data_buf);
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

static ClockCalendar RequestDate() {
    using namespace std;
    string sbuf;

    cout << "\n\nYear: ";
    cin >> sbuf;
    // cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
    int year = stoi(sbuf);

    cout << "Month: ";
    cin >> sbuf;
    // cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
    int month = stoi(sbuf);

    cout << "Day: ";
    cin >> sbuf;
    // cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
    int day = stoi(sbuf);

    cout << "Hour: ";
    cin >> sbuf;
    // cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
    int hour = stoi(sbuf);

    cout << "AM(0) or PM(1): ";
    cin >> sbuf;
    // cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
    int isPm = stoi(sbuf);

    cout << "Minutes: ";
    cin >> sbuf;
    // cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
    int min = stoi(sbuf);

    cout << "Seconds: ";
    cin >> sbuf;
    // cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
    int sec = stoi(sbuf);

    return {day, month, year, hour, min, sec, isPm};
}

void Application::Start() {
    bool exit = false;
    char cmd;
    int value = 0;
    
    std::thread monitor (SerialMonitor);

    Logger& tl = Logger::GetInstance();

    int err = 0;
    while (!exit && !err)
    {
        std::cout << "----- Helmholtz Cage Interface -----\n\n";

        std::cout << "Available commands:\n\n";
        std::cout << "   1 - Set X axis\n";
        std::cout << "   2 - Set Y axis\n";
        std::cout << "   3 - Set Z axis\n";
        std::cout << "   4 - Request event log transmission\n";
        std::cout << "   5 - List all events\n";
        std::cout << "   6 - List events by interval\n\n";
        std::cout << "Command: ";
        std::cin >> cmd;

        char buf[256];
        int nbytes = 0;

        ClockCalendar inStart(0,0,0,0,0,0,0);
        ClockCalendar inEnd(0,0,0,0,0,0,0);

        switch (cmd)
        {
            case '1':
                std::cout << "\nValue to set: ";
                std::cin >> value;
                SendCommand(1, value);
                break;

            case '2':
                std::cout << "\nValue to set: ";
                std::cin >> value;
                SendCommand(2, value);
                break;

            case '3':
                std::cout << "\nValue to set: ";
                std::cin >> value;
                SendCommand(3, value);
                break;

            case '4':
                value = 4;
                m_Host.m_Serial.Write((void*)&value, sizeof(int));
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                break;
            
            case '5':
                tl.ListAll();
                break;

            case '6':
                std::cout << "\nStart time:";
                inStart = RequestDate();
                std::cout << "\nEnd time:";
                inEnd = RequestDate();
                std::cout << inStart.Print() << "\n";
                std::cout << inEnd.Print() << "\n";
                tl.ListInterval(inStart, inEnd);
                break;

            case '0':
                exit = true;
                err = system("clear");
                continue;

            default:
                std::cout << "Invalid commmand.\n\n";
                break;
        }
        WaitKeyPress();
        err = system("clear");
    }

    return;
}

void Application::SendCommand(int axis, int val) {
    int buf[2] = { axis, val };
    m_Host.m_Serial.Write(buf, sizeof(int)*2);
}