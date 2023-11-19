/**
 * \file Calendar.cpp
 * 
 * \brief Calendar class implementation
 * 
 * \author Ramon de Araujo Borba <ramonborba97@gmail.com>
 * 
 * \version 0.1
 * 
 * \date 17-11-2023
 */

#include "Calendar.hpp"

Calendar::Calendar(int t_day, int t_month, int t_year) : m_day(t_day), m_month(t_month), m_year(t_year) {
}

Calendar::~Calendar() {
}

void Calendar::setCalendar(int t_day, int t_month, int t_year) {
    m_day = t_day;
    m_month = t_month;
    m_year = t_year;
}

void Calendar::readCalendar(int& t_day, int& t_month, int& t_year) {
    t_day = m_day;
    t_month = m_month;
    t_year = m_year;
}

void Calendar::advance() {
    m_day++;
    if (m_day > 30) {
        m_day = 1;
        m_month ++;
        if (m_month > 12) {
            m_month = 1;
            m_year++;
        }
    }
}
