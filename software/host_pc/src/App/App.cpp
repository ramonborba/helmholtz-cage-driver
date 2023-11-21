#include <iostream>

#include "App.hpp"
#include "ClockCalendar.hpp"

HostPC HostPC::m_Host;

void HostPC::Start() {
    bool exit = false;
    int command = -1;

    ClockCalendar clk(21,03,1997,3,30,42,1);

    system("clear");
    while (!exit)
    {
        std::cout << "----- Helmholtz Cage Interface -----\n\n";

        std::cout << "Available commands:\n\n";
        std::cout << "   1 - Set X axis\n";
        std::cout << "   2 - Set Y axis\n";
        std::cout << "   3 - Set Z axis\n";
        std::cout << "   4 - Request event log transmission\n";
        std::cout << "   5 - List all events\n\n";
        std::cout << "   6 - List events by interval\n\n";
        std::cout << "Command: ";
        std::cin >> command;

        switch (command)
        {
        case 1:
            std::cout << clk.Print() << std::endl;
            break;

        case 0:
            exit = true;
            system("clear");
            continue;

        default:
            std::cout << "Invalid commmand.\n\n";
            break;
        }
    }

    return;
}