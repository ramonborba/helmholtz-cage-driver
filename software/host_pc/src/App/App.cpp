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
#include <optional>

#include "App.hpp"

Application Application::m_Host;

static void WaitKeyPress() {
    std::cout << "Press Enter to continue.";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::cin.get();
}

void Application::Start() {
    bool exit = false;
    char cmd;

    int err = 0;
    while (!exit && !err)
    {
        err = system("clear");
        std::cout << "----- Helmholtz Cage Interface -----\n\n";

        std::cout << "Available commands:\n\n";
        std::cout << "   1 - Set X axis\n";
        std::cout << "   2 - Set Y axis\n";
        std::cout << "   3 - Set Z axis\n";
        std::cout << "   4 - Request event log transmission\n";
        std::cout << "   5 - List all events\n\n";
        std::cout << "   6 - List events by interval\n\n";
        std::cout << "Command: ";
        std::cin >> cmd;

        switch (cmd)
        {
        case '1':
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
    }

    return;
}