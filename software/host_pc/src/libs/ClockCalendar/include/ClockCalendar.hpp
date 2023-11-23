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

#pragma once

#include <string>

#include "Clock.hpp"
#include "Calendar.hpp"

class ClockCalendar : public Clock, public Calendar {
public:
    ClockCalendar(int t_day, int t_month, int t_year, int t_hr, int t_min, int t_sec, int t_isPm);
    void advance();

    friend bool operator< (ClockCalendar& l, ClockCalendar&r) {
        Clock lclk (l.m_hr, l.m_min, l.m_sec, l.m_isPM);
        Clock rclk (r.m_hr, r.m_min, r.m_sec, r.m_isPM);
        Calendar lcal (l.m_day, l.m_month, l.m_year);
        Calendar rcal (r.m_day, r.m_month, r.m_year);
        if (lcal < rcal) {
            return true;
        }
        else if ((lcal == rcal) && (lclk < rclk)) {
            return true;
        }
        else {
            return false;
        };
    }

    friend bool operator== (ClockCalendar& l, ClockCalendar& r) {
        return (l.m_year == r.m_year) && (l.m_month == r.m_month) && (l.m_day == r.m_day) && (l.m_isPM == r.m_isPM) && (l.m_hr == r.m_hr) && (l.m_min == r.m_min) && (l.m_sec == r.m_sec);
    }

    friend bool operator> (ClockCalendar& l, ClockCalendar& r) {
        return !(l == r) && !(l < r);
    }

    friend bool operator<= (ClockCalendar& l, ClockCalendar& r) {
        return (l == r) || (l < r);
    }

    friend bool operator>= (ClockCalendar& l, ClockCalendar& r) {
        return (l == r) && (l > r);
    }

    friend bool operator!= (ClockCalendar& l, ClockCalendar& r) {
        return !(l == r);
    }

    std::string Print();
};
