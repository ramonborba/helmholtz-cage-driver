/**
 * \file ClockCalendar.cpp
 * 
 * \brief ClockCalendar class implementation
 * 
 * \author Ramon de Araujo Borba <ramonborba97@gmail.com>
 * 
 * \version 0.1
 * 
 * \date 17-11-2023
 */

#include <string>

#include "ClockCalendar.hpp"

ClockCalendar::ClockCalendar(int t_day, int t_month, int t_year, int t_hr, int t_min, int t_sec, int t_isPm) : Clock(t_hr, t_min, t_sec, t_isPm), Calendar(t_day, t_month, t_year) {
}

void ClockCalendar::advance() {
    bool wasPM = m_isPM;
    Clock::advance();
    if (wasPM && !m_isPM) {
        Calendar::advance();
    }
}

std::string ClockCalendar::Print() {
    using str = std::string;

    return str("Date: ") + std::to_string(m_day) + str("/") + std::to_string(m_month) + str("/") + std::to_string(m_year) + str(" Time: ") + std::to_string(m_hr) + str("h") + std::to_string(m_min) + str("m") + std::to_string(m_sec) + str("s") + (m_isPM ? "PM" : "AM");
}
