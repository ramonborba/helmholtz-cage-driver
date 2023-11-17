/**
 * \file ClockCalendar.hpp
 * 
 * \brief ClockCalendar class header file
 * 
 * \author Ramon de Araujo Borba <ramonborba97@gmail.com>
 * 
 * \version 0.1
 * 
 * \date 17-11-2023
 */

#include "Clock.hpp"
#include "Calendar.hpp"

class ClockCalendar : public Clock, public Calendar {
public:
    ClockCalendar(int t_day, int t_month, int t_year, int t_hr, int t_min, int t_sec, int t_isPm);
    void advance();
};
