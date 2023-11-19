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
